/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:24 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 04:31:08 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "defines.h"
#include "errors.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include "map.h"

static void	set_coord(t_map *map, t_line *l)
{
	static int	i;
	int			j;

	j = 0;
	l->splited = ft_split(l->line, ' ', &l->wc);
	while (j < map->mapx)
	{
		if (!ft_isformat(l->splited[j]))
		{
			dbl_free(l->splited);
			error(ERR_FORM);
		}
		map->p[i][j].coord[X] = j;
		map->p[i][j].coord[Y] = i;
		atoi_form(l->splited[j], &map->p[i][j]);
		j++;
	}
	i++;
	dbl_free(l->splited);
}

static void	set_map(t_map *map, char *path)
{
	int		i;
	t_line	l;

	i = 0;
	map->fd = open(path, O_RDONLY);
	if (map->fd < 0)
		error(ERR_OPEN);
	map->p = (t_point **)malloc(map->mapy * sizeof(t_point *));
	if (map->p == NULL)
		error(ERR_MEM);
	while (i < map->mapy)
	{
		map->p[i] = (t_point *)malloc(map->mapx * sizeof(t_point));
		if (map->p[i++] == NULL)
			error(ERR_MEM);
	}
	l.line = get_next_line(map->fd);
	while (l.line != NULL)
	{
		set_coord(map, &l);
		free(l.line);
		l.line = get_next_line(map->fd);
	}
	close (map->fd);
}

static void	get_map_size(t_map *map, char *path)
{
	t_line	l;

	map->fd = open(path, O_RDONLY);
	if (map->fd < 0)
		error(ERR_OPEN);
	l.line = get_next_line(map->fd);
	l.wc = 0;
	while (l.line != NULL)
	{
		l.splited = ft_split(l.line, ' ', &l.wc);
		if (map->mapx == 0)
			map->mapx = l.wc;
		if (map->mapx != l.wc)
			error(ERR_LINE);
		map->mapy++;
		dbl_free(l.splited);
		free(l.line);
		l.line = get_next_line(map->fd);
	}
	close (map->fd);
}

static void	init_map(t_map *map)
{
	map->mapx = 0;
	map->mapy = 0;
}

void	load_map(t_map *map, char *path)
{
	init_map(map);
	get_map_size(map, path);
	set_map(map, path);
}
