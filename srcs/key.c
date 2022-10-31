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
	if (keysym == KEY_1)
	{
		set_bg_color(mlx, DARK_GRAY_PIXEL, PEACH_PASTEL_PIXEL);
	}
	return (0);
}