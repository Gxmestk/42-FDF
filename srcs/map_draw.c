/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:45:30 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/09 17:16:47 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "math.h"
#include "defines.h"
#include "mlx.h"
#include "mlx_optimize.h"
#include "utils.h"
#include "color.h"
#include "transform.h"
#include "map.h"

static void	bresenham_m1(t_img *img, t_point a, t_point b, t_slope *m)
{
	t_gradient	gra;

	gra.t = b.coord[Y] - a.coord[Y];
	gra.cdif = difcolor(a, b);
	gra.ori = itoc(a.color);
	while (a.coord[Y] <= b.coord[Y])
	{
		mlx_gradient(&a, &gra, b.coord[Y] - a.coord[Y]);
		mlx_pix_put(img, a);
		if (a.coord[Y] <= b.coord[Y])
			a.coord[Y]++;
		if (m->p >= 0)
		{
			m->p += 2 * (m->dx - m->dy);
			if (a.coord[X] < b.coord[X])
				a.coord[X]++;
			else if (a.coord[X] > b.coord[X])
				a.coord[X]--;
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
	while (a.coord[X] <= b.coord[X])
	{
		mlx_gradient(&a, &gra, b.coord[X] - a.coord[X]);
		mlx_pix_put(img, a);
		a.coord[X]++;
		if (m->p >= 0)
		{
			m->p += 2 * (m->dy - m->dx);
			if (a.coord[Y] < b.coord[Y])
				a.coord[Y]++;
			else if (a.coord[Y] > b.coord[Y])
				a.coord[Y]--;
		}
		else
			m->p += 2 * m->dy;
	}
}

void	draw_line(t_mlx *mlx, t_point a, t_point b)
{
	t_slope	m;

	if (mlx->tf.istf)
		transform(mlx, &a, &b);
	if (b.coord[X] < a.coord[X])
		swap_point(&a, &b);
	m.dx = abs(b.coord[X] - a.coord[X]);
	m.dy = abs(b.coord[Y] - a.coord[Y]);
	if (m.dy > m.dx)
	{
		if (b.coord[Y] < a.coord[Y])
			swap_point(&a, &b);
		m.p = 2 * m.dx - m.dy;
		bresenham_m1(&mlx->img, a, b, &m);
	}
	else
	{
		m.p = 2 * m.dy - m.dx;
		bresenham_l1(&mlx->img, a, b, &m);
	}
}

void	draw_wireframe(t_mlx *mlx)
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
				draw_line(mlx, a, mlx->map.p[i][j + 1]);
			if (i < mlx->map.mapy - 1)
				draw_line(mlx, a, mlx->map.p[i + 1][j]);
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
	if (mlx->e.menu == YES)
		draw_string(mlx);
	return (0);
}
