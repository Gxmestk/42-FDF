/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:18:17 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 13:55:09 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx_optimize.h"
#include "ft_printf.h"
#include "errors.h"
#include "map.h"
#include "mlx.h"
#include "key.h"
#include "optX.h"
#include "utils.h"
#include "color.h"
#include "transform.h"

static void	mlx_setup(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		error(ERR_MLX);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WX, WY, "FDF");
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		error(ERR_MLX);
	}
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, WX, WY);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, \
		&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		error(ERR_ARGS);
	load_map(&mlx.map, argv[1]);
	mlx_setup(&mlx);
	color_setup(&mlx);
	transform_setup(&mlx);
	if (draw_map(&mlx) < 0)
		error(ERR_MAP);
 /* mlx_hook(meta.vars.win, 3, 0, key_release, &meta);
	mlx_hook(meta.vars.win, 4, 0, mouse_press, &meta);
	mlx_hook(meta.vars.win, 5, 0, mouse_release, &meta);
	mlx_hook(meta.vars.win, 6, 0, mouse_move, &meta);
	mlx_hook(meta.vars.win, 17, 0, terminate_program, &meta);*/
	mlx_loop_hook(mlx.mlx_ptr, no_event, &mlx);
	mlx_hook(mlx.win_ptr, 3, 2, key_release, &mlx);
	mlx_loop(mlx.mlx_ptr);

	free_map(&mlx.map);
	mlx_destroy_image(mlx.mlx_ptr, mlx.img.mlx_img);
	if (OS == LINUX)
		mlx_destroy_display(mlx.mlx_ptr);
	free (mlx.mlx_ptr);
	return (0);
}
