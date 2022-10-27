/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:10:06 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/27 00:47:11 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "math.h"
#include "defines.h"
#include <stdio.h>

void	isometric(t_point *p)
{
	float	ang;
	int		z;

	z = p->coord[Z];
	ang = M_PI / 3;
	p->coord[X] = (p->coord[X] - p->coord[Y]) * cos(ang);
	p->coord[Y] = (p->coord[X] + p->coord[Y]) * sin(ang) - z;
	p->coord[X] += WX / 2;
	p->coord[Y] += WY / 2;
}
