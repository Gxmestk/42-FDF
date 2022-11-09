/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:41:56 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/09 17:11:02 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_optimize.h"
#include "defines.h"
#include "color.h"
#include <math.h>

#if __APPLE__

int	mlx_destroy_display(void *ptr)
{
	(void)ptr;
	return (0);
}
#endif

void	mlx_gradient(t_point *a, t_gradient *gra, int dis)
{
	float	frac;
	t_color	ac;

	ac = itoc(a->color);
	if (gra->t == 0)
		return ;
	frac = 1 - (float)dis / (float)gra->t;
	ac.red = gra->cdif.red * frac + gra->ori.red;
	ac.green = gra->cdif.green * frac + gra->ori.green;
	ac.blue = gra->cdif.blue * frac + gra->ori.blue;
	a->color = (ac.blue ^ (ac.green << 8) ^ (ac.red << 16));
}

void	mlx_pix_put(t_img *img, t_point p)
{
	char	*pixel;
	int		i;

	if ((p.coord[X] < 0 || p.coord[X] > WX)
		|| (p.coord[Y] < 0 || p.coord[Y] > WY))
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (int)(p.coord[Y] * img->line_len \
		+ p.coord[X] * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (p.color >> i) & 0xFF;
		else
			*pixel++ = (p.color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
/*void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		//big endian, MSB is the leftmost bit
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		//little endian, LSB is the leftmost bit
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}*/
