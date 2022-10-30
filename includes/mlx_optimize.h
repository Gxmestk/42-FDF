/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_optimize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:41:22 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 17:35:58 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_OPTIMIZE
#define MLX_OPTIMIZE

#include "defines.h"

void mlx_pix_put(t_img *img, t_point p);
void mlx_gradient(t_point *a, t_gradient *gra, int dis);
void draw_basicbg(t_mlx *mlx);
void img_pix_put(t_img *img, int x, int y, int color);
#endif
