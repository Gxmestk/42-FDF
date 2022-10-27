/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:45:30 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/27 00:49:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "defines.h"
#include "mlx.h"
#include "mlx_optimize.h"
#include "unistd.h"
#include "ft_printf.h"
#include "utils.h"
#include "color.h"
#include "transform.h"

static void	bresenham_m1(t_img *img, t_point a, t_point b, t_slope *m)
{
	t_gradient	gra;

	gra.t = b.coord[Y] - a.coord[Y];
	gra.cdif = difcolor(a, b);
	gra.ori = itoc(a.color);
	while (a.coord[Y] <= b.coord[Y] || a.coord[X] <= b.coord[X])
	{
		mlx_gradient(&a, &gra, b.coord[Y] - a.coord[Y]);
		mlx_pix_put(img, a);
		if (a.coord[Y] <= b.coord[Y])
			a.coord[Y]++;
		else
			a.coord[Y]--;
		if (m->p >= 0)
		{
			m->p += 2 * (m->dx - m->dy);
			a.coord[X]++;
		}
		else
			m->p += 2 * m->dx;
	}
}

static void	bresenham_l1(t_img *img, t_point a, t_point b, t_slope *m)
{
	t_gradient	gra;

	gra.t = b.coord[X] - a.coord[X];
	gra.cdif = difcolor(a, b);
	gra.ori = itoc(a.color);
	while (a.coord[X] <= b.coord[X] || a.coord[Y] != b.coord[Y])
	{
		mlx_gradient(&a, &gra, b.coord[X] - a.coord[X]);
		mlx_pix_put(img, a);
		a.coord[X]++;
		if (m->p >= 0)
		{
			m->p += 2 * (m->dy - m->dx);
			if (a.coord[Y] < b.coord[Y])
				a.coord[Y]++;
			else
				a.coord[Y]--;
		}
		else
			m->p += 2 * m->dy;
	}
}

static void	draw_line(t_img *img, t_point a, t_point b)
{
	t_slope	m;

	isometric(&a);
	isometric(&b);
	if (b.coord[X] < a.coord[X])
		swap_point(&a, &b);
	if (a.coord[Z] > 0)
		a.color = RED_PIXEL;
	if (b.coord[Z] > 0)
		b.color = RED_PIXEL;
	m.dx = abs(b.coord[X] - a.coord[X]);
	m.dy = abs(b.coord[Y] - a.coord[Y]);
	if (m.dy > m.dx)
	{
		m.p = 2 * m.dx - m.dy;
		bresenham_m1(img, a, b, &m);
	}
	else
	{
		m.p = 2 * m.dy - m.dx;
		bresenham_l1(img, a, b, &m);
	}
}

static void	draw_wireframe(t_mlx *mlx)
{
	t_point		a;
	int			i;
	int			j;

	i = 0;
	while (i < mlx->map.mapy)
	{
		j = 0;
		while (j < mlx->map.mapx)
		{
			a = mlx->map.p[i][j];
			if (j < mlx->map.mapx - 1)
				draw_line(&mlx->img, a, mlx->map.p[i][j + 1]);	
			if (i < mlx->map.mapy - 1)
				draw_line(&mlx->img, a, mlx->map.p[i + 1][j]);
			j++;
		}
		i++;
	}
}

int	draw_map(t_mlx *mlx)
{
	if (mlx->win_ptr == NULL)
		return (-1);
	draw_background(mlx);
	draw_wireframe(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mlx_img, 0, 0);
	return (0);
}
