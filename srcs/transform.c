/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:40 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 00:32:05 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "transform.h"

void	set_pov(int *pov, int mode)
{
	*pov = mode;
}

void	transform_setup(t_mlx *mlx)
{
	mlx->tf.angx = 0;
	mlx->tf.angy = 0;
	mlx->tf.angz = 0;
	mlx->tf.tx = 0;
	mlx->tf.ty = 0;
	mlx->tf.tz = 0;
	set_pov(&mlx->tf.pov , ISO);
}

void	transform(t_mlx *mlx, t_point *a, t_point *b)
{
	/*if (mlx->tf.pov == ISO)
		isometric(a, b);*/
	//else if (mlx->pov == PAR)
	rotate(&mlx->tf, a, b, X);
	rotate(&mlx->tf, a, b, Y);
	rotate(&mlx->tf, a, b, Z);
	translate(&mlx->tf, a, b, X);
	translate(&mlx->tf, a, b, Y);
}