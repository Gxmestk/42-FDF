/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:36:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 06:10:20 by tkhemniw         ###   ########.fr       */
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

static void	color_key(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_1)
		color_setup(mlx);
	if (keysym == KEY_2)
	{
		set_bg_color(mlx, DARK_GRAY_PIXEL, PEACH_PASTEL_PIXEL);
		set_map_color(&mlx->map, WHITE_PIXEL, BLUE_PIXEL);
	}
	if (keysym == KEY_3)
	{
		set_bg_color(mlx, GREEN_PIXEL, BLUE_PIXEL);
		set_map_color(&mlx->map, LIGHT_GRAY_PIXEL, BLACK_PIXEL);
	}
}

static void	transform_key(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_TAB)
	{
		if (mlx->tf.pov == ISO)
			set_pov(&mlx->tf, TOP);
		else
			set_pov(&mlx->tf, ISO);
	}	
	if (keysym == KEY_r)
		transform_setup(mlx);
	if (keysym == KEY_space)
	{
		if (mlx->e.anim == NO)
			mlx->e.anim = ROTZ;
		else
			mlx->e.anim = NO;
	}
	if (keysym == KEY_z)
	{
		mlx->tf.scalez *= 1.25;
	}
	if (keysym == KEY_x)
	{
		mlx->tf.scalez /= 1.25;
	}
}

int	key_release(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_ESC)
		close_window(mlx);
	color_key(keysym, mlx);
	transform_key(keysym, mlx);
	return (0);
}
