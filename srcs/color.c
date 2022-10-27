/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:09:46 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/27 00:34:54 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include <stdio.h>

t_color	difcolor(t_point a, t_point b)
{
	t_color	ac;
	t_color	bc;
	t_color	dif;

	ac = itoc(a.color);
	bc = itoc(b.color);
	dif.red = bc.red - ac.red;
	dif.green = bc.green - ac.green;
	dif.blue = bc.blue - ac.blue;
	return (dif);
}

t_color	itoc(int color)
{
	t_color	ret;

	ret.blue = color & 0x0000FF;
	color >>= 8;
	ret.green = color & 0x0000FF;
	color >>= 8;
	ret.red = color & 0x0000FF;
	return (ret);
}
//set_map_color()
