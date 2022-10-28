/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:22:24 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 02:20:18 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "ft_printf.h"
#include "key.h"
#include "defines.h"
#include "mlx.h"
#include "map.h"
#include "unistd.h"
#include "transform.h"
#include "color.h"
#include "math.h"

int	no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	key_release(int keysym, t_mlx *mlx)
{
	static int i;
	i++;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	if (keysym == XK_1)
	{
		set_bg_color(mlx, DARK_GRAY_PIXEL, PEACH_PASTEL_PIXEL);
		draw_map(mlx);
	}
	if (keysym == XK_2)
	{
		set_rot_ang(mlx, M_PI / 6, X);
		draw_map(mlx);
	}
	if (keysym == XK_3)
	{
		set_rot_ang(mlx, -(M_PI / 6), X);
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
