/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:15:41 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 09:42:48 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "defines.h"

int		animate(t_mlx *mlx);
int		key_release(int keysym, t_mlx *mlx);
int		mouse_press(int butsym, int x, int y, t_mlx *mlx);
int		mouse_release(int butsym, int x, int y, t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *mlx);
void	event_setup(t_mlx *mlx);
void	colorize(t_map *map, t_point *a, t_point *b);

#endif