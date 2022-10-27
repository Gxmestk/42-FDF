/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:19:03 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/24 11:55:22 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
#define KEY_H

#include "defines.h"

int	no_event(t_mlx *mlx);
int	key_release(int keysym, t_mlx *mlx);

#endif