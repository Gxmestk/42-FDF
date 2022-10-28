/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:49:51 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 01:35:52 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

void	translate(t_transform *tf, t_point *a, t_point *b,int axis)
{
	if (axis == X)
	{
		a->coord[X] += tf->tx;
		b->coord[X] += tf->tx;
	}
	if (axis == Y)
	{
		a->coord[Y] += tf->ty;
		b->coord[Y] += tf->ty;
	}
}