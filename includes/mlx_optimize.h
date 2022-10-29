/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_optimize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:41:22 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/29 05:56:31 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_OPTIMIZE
# define MLX_OPTIMIZE

# include "defines.h"

void	mlx_pix_put(t_img *img, t_point p);
void	mlx_gradient(t_point *a, t_gradient *gra, int dis);

#endif

