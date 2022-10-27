/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:06:53 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/27 13:26:27 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "defines.h"

t_color	itoc(int color);
t_color difcolor(t_point a, t_point b);
void	set_map_color(t_map *map, int color);
void	set_bg_color(t_mlx *mlx, int color_from, int color_to);
void	color_setup(t_mlx *mlx);

#endif