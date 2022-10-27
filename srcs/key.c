/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:22:24 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/25 10:13:41 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "ft_printf.h"
#include "key.h"
#include "defines.h"
#include "mlx.h"
#include "map.h"
#include "unistd.h"

int	no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	key_release(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	if (keysym == XK_1)
	{
		draw_map(mlx);
	}
	return (0);
}
