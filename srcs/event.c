/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:15:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 10:04:10 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "defines.h"
#include "mlx.h"
#include "map.h"
#include "unistd.h"
#include "transform.h"
#include "color.h"
#include "math.h"
#include "utils.h"
#include <stdio.h>

int	animate(t_mlx *mlx)
{
	if (mlx->e.anim == ROTZ)
		add_rot_ang(mlx, M_PI / 60, Z);
	draw_map(mlx);
	return (0);
}

void	event_setup(t_mlx *mlx)
{
	mlx->e.anim = NO;
	mlx->e.l_ck = NO;
	mlx->e.r_ck = NO;
	mlx->e.menu = NO;
}

void	colorize(t_map *map, t_point *a, t_point *b)
{
	if (a->color == BLACK_PIXEL && a->coord[Z] > 0)
		a->color = map->cto;
	else if (a->color == BLACK_PIXEL)
		a->color = map->cfrom;
	if (b->color == BLACK_PIXEL && b->coord[Z] > 0)
		b->color = map->cto;
}
