/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:39:20 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/26 03:39:40 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "defines.h"
#include "mlx_optimize.h"

void	swap_point(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	dbl_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

void	draw_background(t_mlx *mlx)
{
	t_point	p;

	p.coord[Y] = 0;
	p.color = 0;
	while (p.coord[Y] < WY)
	{
		p.coord[X] = 0;
		while (p.coord[X] < WX)
		{
			mlx_pix_put(&mlx->img, p);
			p.coord[X]++;
		}
		p.coord[Y]++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->mapy)
		free(map->p[i++]);
	free(map->p);
	i = 0;
}
