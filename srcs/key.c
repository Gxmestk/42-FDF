/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:36:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 17:44:07 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optkeysym.h"
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

int	key_release(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_ESC)
		close_window(mlx);
	if (keysym == XK_1)
	{
		set_bg_color(mlx, DARK_GRAY_PIXEL, PEACH_PASTEL_PIXEL);
	}
	if (keysym == XK_2)
	{
		add_rot_ang(mlx, M_PI / 18, X);
	}
	if (keysym == XK_3)
	{
		add_rot_ang(mlx, -(M_PI / 18), X);
	}
	if (keysym == XK_4)
	{
		add_rot_ang(mlx, M_PI / 18, Y);
	}
	if (keysym == XK_5)
	{
		add_rot_ang(mlx, -(M_PI / 18), Y);
	}
	if (keysym == XK_6)
	{
		add_rot_ang(mlx, M_PI / 18, Z);
	}
	if (keysym == XK_7)
	{
		add_rot_ang(mlx, -(M_PI / 18), Z);
	}
	if (keysym == XK_w)
	{
		printf("tx ty  = %d,%d\n",mlx->tf.tx,mlx->tf.ty);
		mlx->tf.ty -= 10;
	}
	if (keysym == XK_d)
	{
		printf("tx ty  = %d,%d\n",mlx->tf.tx,mlx->tf.ty);
		mlx->tf.tx += 10;
	}
	if (keysym == XK_s)
	{
		printf("tx ty  = %d,%d\n",mlx->tf.tx,mlx->tf.ty);
		mlx->tf.ty += 10;
	}
	if (keysym == XK_a)
	{
		printf("tx ty  = %d,%d\n",mlx->tf.tx,mlx->tf.ty);
		mlx->tf.tx -= 10;
	}
	return (0);
}