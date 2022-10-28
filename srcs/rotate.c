/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:10:06 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 01:40:06 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "math.h"
#include "defines.h"
#include <stdio.h>

void	isometric(t_point *a, t_point *b)
{
	float	ang;
	int		z;

	z = a->coord[Z];
	ang = M_PI / 3;
	a->coord[X] = (a->coord[X] - a->coord[Y]) * cos(ang);
	a->coord[Y] = (a->coord[X] + a->coord[Y]) * sin(ang) - z;
	a->coord[X] += WX / 2;
	a->coord[Y] += WY / 2;
	z = b->coord[Z];
	b->coord[X] = (b->coord[X] - b->coord[Y]) * cos(ang);
	b->coord[Y] = (b->coord[X] + b->coord[Y]) * sin(ang) - z;
	b->coord[X] += WX / 2;
	b->coord[Y] += WY / 2;
}

void	set_rot_ang(t_mlx *mlx, float ang, int axis)
{
	if (axis == X)
		mlx->tf.angx += ang;
	if (axis == Y)
		mlx->tf.angy += ang;
	if (axis == Z)
		mlx->tf.angz += ang;
}

void	rotate(t_transform *tf, t_point *a, t_point *b, int axis)
{
	if (axis == X)
	{
		a->coord[Y] = a->coord[Y] * cos(tf->angx) - a->coord[Z] * sin(tf->angx);
		a->coord[Z] = a->coord[Z] * cos(tf->angx) + a->coord[Y] * sin(tf->angx);
		b->coord[Y] = b->coord[Y] * cos(tf->angx) - b->coord[Z] * sin(tf->angx);
		b->coord[Z] = b->coord[Z] * cos(tf->angx) + b->coord[Y] * sin(tf->angx);
	}
	if (axis == Y)
	{
		a->coord[X] = a->coord[X] * cos(tf->angy) - a->coord[Z] * sin(tf->angy);
		a->coord[Z] = a->coord[Z] * cos(tf->angy) + a->coord[X] * sin(tf->angy);
		b->coord[X] = b->coord[X] * cos(tf->angy) - b->coord[Z] * sin(tf->angy);
		b->coord[Z] = b->coord[Z] * cos(tf->angy) + b->coord[X] * sin(tf->angy);
	}
	if (axis == Z)
	{
		a->coord[X] = a->coord[X] * cos(tf->angz) - a->coord[Y] * sin(tf->angz);
		a->coord[Y] = a->coord[Y] * cos(tf->angz) + a->coord[X] * sin(tf->angz);
		b->coord[X] = b->coord[X] * cos(tf->angz) - b->coord[Y] * sin(tf->angz);
		b->coord[Y] = b->coord[Y] * cos(tf->angz) + b->coord[X] * sin(tf->angz);
	}
}
