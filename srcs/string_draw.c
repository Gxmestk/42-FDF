/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 07:31:05 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 09:04:30 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "defines.h"

void	draw_string(t_mlx *mlx)
{
	if (WX < 300 || WY < 300)
		return ;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		20, WHITE_PIXEL, "Left Drag: Translate");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		40, WHITE_PIXEL, "Right Drag: Rotate");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		60, WHITE_PIXEL, "Space: Animate Rotate on Z-axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		80, WHITE_PIXEL, "Z : Scale Up Z");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		100, WHITE_PIXEL, "X : Scale Down Z");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		120, WHITE_PIXEL, "Tab : Switch Projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		140, WHITE_PIXEL, "1, 2, 3 : Change Color");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		160, WHITE_PIXEL, "R : Reset Transform");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10,
		180, WHITE_PIXEL, "ESC : Exit Program");
}
