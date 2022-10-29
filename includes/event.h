/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:15:41 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 08:53:49 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
#define EVENT_H

#include "defines.h"

int	no_event(t_mlx *mlx);
int	key_release(int keysym, t_mlx *mlx);
int	mouse_press(int butsym, int x, int y, t_mlx *mlx);
int	mouse_release(int butsym, t_mlx *mlx);
int	mouse_move(int x, int y, t_mlx *mlx);

#endif