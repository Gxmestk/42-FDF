/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:40 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 06:14:11 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "transform.h"
#include "math.h"
#include "event.h"

void	midwin_origin(t_point *a, t_point *b)
{
	a->coord[X] += WX / 2;
	a->coord[Y] += WY / 2;
	b->coord[X] += WX / 2;
	b->coord[Y] += WY / 2;
}

void	midmap_origin(t_mlx *mlx, t_point *a, t_point *b)
{
	a->coord[X] -= (mlx->map.mapx - 1) * mlx->tf.scale / 2;
	a->coord[Y] -= (mlx->map.mapy - 1) * mlx->tf.scale / 2;
	b->coord[X] -= (mlx->map.mapx - 1) * mlx->tf.scale / 2;
	b->coord[Y] -= (mlx->map.mapy - 1) * mlx->tf.scale / 2;
}

void	set_pov(t_transform *tf, int mode)
{
	tf->pov = mode;
}

void	transform_setup(t_mlx *mlx)
{
	mlx->tf.angx = 0;
	mlx->tf.angy = 0;
	mlx->tf.angz = 0;
	mlx->tf.tx = 0;
	mlx->tf.ty = 0;
	mlx->tf.scale = 1;
	mlx->tf.scalez = 1;
	set_pov(&mlx->tf, ISO);
}

void	transform(t_mlx *mlx, t_point *a, t_point *b)
{
	colorize(&mlx->map, a, b);
	scale(&mlx->tf, a, b);
	midmap_origin(mlx, a, b);
	if (mlx->tf.pov == ISO)
		isometric(a, b);
	rotate(&mlx->tf, a, b, X);
	rotate(&mlx->tf, a, b, Y);
	rotate(&mlx->tf, a, b, Z);
	translate(&mlx->tf, a, b, X);
	translate(&mlx->tf, a, b, Y);
	midwin_origin(a, b);
}
