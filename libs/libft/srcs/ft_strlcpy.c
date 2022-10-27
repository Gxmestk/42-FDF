/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:35:19 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/25 09:17:52 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy_no_endl(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != '\n' && src[len])
	{
		if (len + 1 < size)
		{
			i++;
			dst[len] = src[len];
		}
		len++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (len);
}
