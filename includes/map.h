/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:35:22 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 17:14:05 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "defines.h"

void	load_map(t_map *map, char *path);
int		draw_map(t_mlx *mlx);
void	draw_line(t_mlx *mlx, t_point a, t_point b);
void	draw_wireframe(t_mlx *mlx);

#endif