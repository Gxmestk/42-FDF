/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:09:57 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 07:26:46 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "defines.h"

void	isometric(t_point *a, t_point *b);
void	transform_setup(t_mlx *mlx);
void	transform(t_mlx *mlx, t_point *a, t_point *b);
void	set_pov(t_transform *tf, int mode);
void	rotate(t_transform *tf, t_point *a, t_point *b, int axis);
void	set_rot_ang(t_mlx *mlx, float ang, int axis);
void	translate(t_transform *tf, t_point *a, t_point *b,int axis);
void	midmap_origin(t_mlx *mlx, t_point *a, t_point *b);
void	midwin_origin(t_point *a, t_point *b);
#endif