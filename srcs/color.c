/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:09:46 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 05:19:18 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include <stdio.h>

t_color	difcolor(t_point a, t_point b)
{
	t_color	ac;
	t_color	bc;
	t_color	dif;

	ac = itoc(a.color);
	bc = itoc(b.color);
	dif.red = bc.red - ac.red;
	dif.green = bc.green - ac.green;
	dif.blue = bc.blue - ac.blue;
	return (dif);
}

t_color	itoc(int color)
{
	t_color	ret;

	ret.blue = color & 0x0000FF;
	color >>= 8;
	ret.green = color & 0x0000FF;
	color >>= 8;
	ret.red = color & 0x0000FF;
	return (ret);
}

void	set_bg_color(t_mlx *mlx, int color_from, int color_to)
{
	mlx->bg.from = color_from;
	mlx->bg.to = color_to;
}

void	set_map_color(t_map *map, int color_from, int color_to)
{
	map->cfrom = color_from;
	map->cto = color_to;
}

void	color_setup(t_mlx *mlx)
{
	set_bg_color(mlx, BLACK_PIXEL, DARK_GRAY_PIXEL);
	set_map_color(&mlx->map, WHITE_PIXEL, RED_PIXEL);
}
