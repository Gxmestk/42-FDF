/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:39:20 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 08:34:36 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "defines.h"
#include "mlx_optimize.h"
#include "map.h"
#include "mlx.h"

void	swap_point(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	dbl_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

void	draw_background(t_mlx *mlx)
{
	t_point	a;
	t_point	b;

	mlx->tf.istf = NO;
	a.color = mlx->bg_color_f;
	b.color = mlx->bg_color_t;
	a.coord[X] = 0;
	a.coord[Y] = 0;
	b.coord[X] = WX;
	b.coord[Y] = 0;
	while (a.coord[Y] <= WY)
	{
		draw_line(mlx, a, b);
		a.coord[Y]++;
		b.coord[Y]++;
	}
	mlx->tf.istf = YES;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->mapy)
		free(map->p[i++]);
	free(map->p);
	i = 0;
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	return (0);
}
