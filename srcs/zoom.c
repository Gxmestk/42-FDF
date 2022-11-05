/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:49:53 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 06:12:00 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

void	scale(t_transform *tf, t_point *a, t_point *b)
{
	a->coord[X] *= tf->scale;
	a->coord[Y] *= tf->scale;
	a->coord[Z] *= tf->scale * tf->scalez;
	b->coord[X] *= tf->scale;
	b->coord[Y] *= tf->scale;
	b->coord[Z] *= tf->scale * tf->scalez;
}
