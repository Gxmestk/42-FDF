/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:51:49 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/25 10:02:23 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigits(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnumeric(char *s)
{
	int	i;

	i = 1;
	if (!(s[0] == '-' || s[0] == '+' || ft_isdigits(s[0])))
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigits(s[i]))
			return (0);
		i++;
	}
	return (1);
}
