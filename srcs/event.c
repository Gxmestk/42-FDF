/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:15:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 17:40:32 by tkhemniw         ###   ########.fr       */
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

int	no_event(t_mlx *mlx)
{
	(void)mlx;
	/*if (mlx->tf.anim == ROTZ)
	{
		add_rot_ang(mlx, M_PI / 60, Z);
		draw_map(mlx);
	}*/
	//mlx->tf.tx++;
	draw_map(mlx);
	return (0);
}

void	event_setup(t_mlx *mlx)
{
	mlx->e.anim = NO;
	mlx->e.l_ck = NO;
	mlx->e.r_ck = NO;
}
