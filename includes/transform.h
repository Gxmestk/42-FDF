/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:09:57 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 01:36:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "defines.h"

void	isometric(t_point *a, t_point *b);
void	transform_setup(t_mlx *mlx);
void	transform(t_mlx *mlx, t_point *a, t_point *b);
void	set_pov(int *pov, int mode);
void	rotate(t_transform *tf, t_point *a, t_point *b, int axis);
void	set_rot_ang(t_mlx *mlx, float ang, int axis);
void	translate(t_transform *tf, t_point *a, t_point *b,int axis);
#endif