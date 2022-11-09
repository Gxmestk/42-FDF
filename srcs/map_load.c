/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:24 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/09 18:54:47 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "defines.h"
#include "errors.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include "map.h"

static void	set_coord(t_mlx *mlx, t_line *l)
{
	static int	i;
	int			j;

	j = 0;
	l->splited = ft_split(l->line, ' ', &l->wc);
	while (j < mlx->map.mapx)
	{
		if (!ft_isformat(l->splited[j]))
		{
			free(l->line);
			dbl_free(l->splited);
			error(ERR_FORM, mlx);
		}
		mlx->map.p[i][j].coord[X] = j;
		mlx->map.p[i][j].coord[Y] = i;
		atoi_form(l->splited[j], &mlx->map.p[i][j]);
		j++;
	}
	i++;
	dbl_free(l->splited);
}

static void	set_map(t_mlx *mlx, char *path)
{
	int		i;
	t_line	l;

	i = 0;
	mlx->map.fd = open(path, O_RDONLY);
	if (mlx->map.fd < 0)
		error(ERR_OPEN, mlx);
	mlx->map.p = (t_point **)malloc(mlx->map.mapy * sizeof(t_point *));
	if (mlx->map.p == NULL)
		error(ERR_MEM, mlx);
	while (i < mlx->map.mapy)
	{
		mlx->map.p[i] = (t_point *)malloc(mlx->map.mapx * sizeof(t_point));
		if (mlx->map.p[i++] == NULL)
			error(ERR_MEM, mlx);
	}
	l.line = get_next_line(mlx->map.fd);
	while (l.line != NULL)
	{
		set_coord(mlx, &l);
		free(l.line);
		l.line = get_next_line(mlx->map.fd);
	}
	close (mlx->map.fd);
}

static void	get_map_size(t_mlx *mlx, char *path)
{
	t_line	l;

	mlx->map.fd = open(path, O_RDONLY);
	if (mlx->map.fd < 0)
		error(ERR_OPEN, mlx);
	l.line = get_next_line(mlx->map.fd);
	l.wc = 0;
	while (l.line != NULL)
	{
		l.splited = ft_split(l.line, ' ', &l.wc);
		if (mlx->map.mapx == 0)
			mlx->map.mapx = l.wc;
		mlx->map.mapy++;
		dbl_free(l.splited);
		free(l.line);
		if (mlx->map.mapx != l.wc)
			error(ERR_LINE, mlx);
		l.line = get_next_line(mlx->map.fd);
	}
	close (mlx->map.fd);
}

static void	init_map(t_map *map)
{
	map->mapx = 0;
	map->mapy = 0;
}

void	load_map(t_mlx *mlx, char *path)
{
	init_map(&mlx->map);
	get_map_size(mlx, path);
	set_map(mlx, path);
}
