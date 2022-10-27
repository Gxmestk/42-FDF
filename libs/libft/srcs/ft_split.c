/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:35:05 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/25 09:30:03 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s && *s != '\n')
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static	size_t	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	char	*wordcpy(char const *s, char c)
{
	char	*str;

	str = malloc(wordlen(s, c) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy_no_endl(str, s, wordlen(s, c) + 1);
	return (str);
}

char	**ft_split(char const *s, char c, int *wc)
{
	char	**res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	*wc = wordcount(s, c);
	res = malloc((*wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s && *s != '\n')
		{
			res[i] = wordcpy(s, c);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}
