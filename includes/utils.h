/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:02:04 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/26 03:39:59 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "defines.h"

void	dbl_free(char **ptr);
void	free_map(t_map *map);
void	atoi_form(char *str, t_point *p);
void	draw_background(t_mlx *mlx);
void	swap_point(t_point *a, t_point *b);
#endif