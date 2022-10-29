/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:10:06 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 08:07:30 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "math.h"
#include "defines.h"
#include <stdio.h>

void	isometric(t_point *a, t_point *b)
{
	float	ang;

	ang = M_PI / 3;
	a->coord[X] = (a->coord[X] - a->coord[Y]) * cos(ang);
	a->coord[Y] = (a->coord[X] + a->coord[Y]) * sin(ang) - a->coord[Z];
	b->coord[X] = (b->coord[X] - b->coord[Y]) * cos(ang);
	b->coord[Y] = (b->coord[X] + b->coord[Y]) * sin(ang) - b->coord[Z];
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

static void	rot(int *x, int *y, float ang)
{
	int	tmp;

	tmp = *x;
	*x = *x * cos(ang) - *y * sin(ang);
	*y = *y * cos(ang) + tmp * sin(ang);
}

void	rotate(t_transform *tf, t_point *a, t_point *b, int axis)
{
	if (axis == X)
	{
		rot(&a->coord[Y], &a->coord[Z], tf->angx);
		rot(&b->coord[Y], &b->coord[Z], tf->angx);
	}
	if (axis == Y)
	{
		rot(&a->coord[X], &a->coord[Z], tf->angy);
		rot(&b->coord[X], &b->coord[Z], tf->angy);
	}
	if (axis == Z)
	{
		rot(&a->coord[Y], &a->coord[X], tf->angz);
		rot(&b->coord[Y], &b->coord[X], tf->angz);
	}
}
