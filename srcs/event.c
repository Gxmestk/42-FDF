/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:15:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 09:44:20 by tkhemniw         ###   ########.fr       */
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
#include "key.h"
#include "mouse.h"
#include "utils.h"
#include <stdio.h>

int	no_event(t_mlx *mlx)
{
	(void)mlx;
	/*if (mlx->tf.anim == ROTZ)
	{
		add_rot_ang(mlx, M_PI / 60, Z);
		draw_map(mlx);
	}*/
	return (0);
}

int	mouse_release(int butsym, t_mlx *mlx)
{
	(void)mlx;
	printf("r/butsym = %d \n", butsym);
	if (butsym == LEFT_CK)

	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->e.l_ck == YES)
	{
		mlx->tf.tx = x;
		mlx->tf.ty = y;

	}
		
	if (mlx->e.r_ck == YES)
}

int	mouse_press(int butsym, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	(void)y;
	printf("butsym = %d  (%d,%d)\n", butsym, x, y);
	if (butsym == KEY_)
	return (0);
}

int	key_release(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_ESC)
		close_window(mlx);
	if (keysym == XK_1)
	{
		set_bg_color(mlx, DARK_GRAY_PIXEL, PEACH_PASTEL_PIXEL);
		draw_map(mlx);
	}
	if (keysym == XK_2)
	{
		add_rot_ang(mlx, M_PI / 18, X);
		draw_map(mlx);
	}
	if (keysym == XK_3)
	{
		add_rot_ang(mlx, -(M_PI / 18), X);
		draw_map(mlx);
	}
	if (keysym == XK_4)
	{
		add_rot_ang(mlx, M_PI / 18, Y);
		draw_map(mlx);
	}
	if (keysym == XK_5)
	{
		add_rot_ang(mlx, -(M_PI / 18), Y);
		draw_map(mlx);
	}
	if (keysym == XK_6)
	{
		add_rot_ang(mlx, M_PI / 18, Z);
		draw_map(mlx);
	}
	if (keysym == XK_7)
	{
		add_rot_ang(mlx, -(M_PI / 18), Z);
		draw_map(mlx);
	}
	if (keysym == XK_w)
	{
		mlx->tf.ty -= 10;
		draw_map(mlx);
	}
	if (keysym == XK_d)
	{
		mlx->tf.tx += 10;
		draw_map(mlx);
	}
	if (keysym == XK_s)
	{
		mlx->tf.ty += 10;
		draw_map(mlx);
	}
	if (keysym == XK_a)
	{
		mlx->tf.tx -= 10;
		draw_map(mlx);
	}
	return (0);
}
