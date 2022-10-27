/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:42:02 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/25 10:11:56 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_ishexdigit(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

int	ft_ishash(int c, int cn)
{
	return (c == '0' && (cn == 'x' || cn == 'X'));
}

int	ft_ishex(char *s)
{
	int	i;

	i = 2;
	if (!ft_ishash(s[0], s[1]))
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_ishexdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isformat(char *s)
{
	int	i;

	i = 1;
	if (!(s[0] == '-' || s[0] == '+' || ft_isdigits(s[0])))
		return (0);
	if (ft_isnumeric(s))
		return (1);
	while (ft_isdigits(s[i]))
		i++;
	if (s[i] == ',')
		i++;
	else
		return (0);
	if (ft_ishex(&s[i]))
		return (1);
	return (0);
}
