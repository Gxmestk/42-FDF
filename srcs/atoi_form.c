/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:29 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/27 00:08:15 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:01:26 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/24 16:33:31 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "utils.h"
#include "libft.h"
#include <stdio.h>

static void	ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

static int	ft_atohi(char *str)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	ft_tolower(str);
	while (ft_ishexdigit(str[i]))
	{
		if (ft_isdigits(str[i]))
			result = (result * 16) + (str[i++] - '0');
		else
			result = (result * 16) + (str[i++] - 'a' + 10);
	}
	return (result);
}

void	atoi_form(char *str, t_point *p)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
			i++;
	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	else if (str[i] == '+')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i++] - 48);
	if (str[i++] == ',')
		p->color = ft_atohi(&str[i]);
	else
		p->color = WHITE_PIXEL;
	p->coord[Z] = result * sign;
}
