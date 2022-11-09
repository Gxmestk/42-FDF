/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:18:17 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/09 18:39:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_optimize.h"
#include "errors.h"
#include "map.h"
#include "mlx.h"
#include "event.h"
#include "utils.h"
#include "color.h"
#include "transform.h"
#include "event.h"

static void	mlx_initialize(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.mlx_img = NULL;
	mlx->map.p = NULL;
}

static void	mlx_setup(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		error(ERR_MLX, mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WX, WY, "FDF Buy tkhemniw");
	if (mlx->win_ptr == NULL)
		error(ERR_MLX, mlx);
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, WX, WY);
	if (mlx->img.mlx_img == NULL)
		error(ERR_MLX, mlx);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, \
		&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx_initialize(&mlx);
	if (argc != 2)
		error(ERR_ARGS, &mlx);
	mlx_setup(&mlx);
	load_map(&mlx, argv[1]);
	color_setup(&mlx);
	event_setup(&mlx);
	transform_setup(&mlx);
	if (draw_map(&mlx) < 0)
		error(ERR_MAP, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, animate, &mlx);
	mlx_hook(mlx.win_ptr, 4, B_PRSMASK, mouse_press, &mlx);
	mlx_hook(mlx.win_ptr, 5, B_RELMASK, mouse_release, &mlx);
	mlx_hook(mlx.win_ptr, 6, B_MOTMASK, mouse_move, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_hook(mlx.win_ptr, 3, K_RELMASK, key_release, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
