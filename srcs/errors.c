/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:23:36 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/09 18:55:49 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "errors.h"
#include "libft.h"
#include "utils.h"
#include "defines.h"
#include "mlx.h"

void	error(char *s, t_mlx *mlx)
{
	if (errno == 0)
		ft_putendl_fd(s, STDERR_FILENO);
	else
		perror(s);
	free_map(&mlx->map);
	if (mlx->mlx_ptr)
	{
		if (mlx->img.mlx_img)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
		mlx->img.mlx_img = NULL;
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	exit(1);
}
