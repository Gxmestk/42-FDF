/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 06:31:12 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/24 16:44:17 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlcpy_no_endl(char *dst, const char *src, size_t dstsize);
char	**ft_split(const char *s, char c, int *wc);
size_t	ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isnumeric(char *s);
int		ft_isdigits(int c);
int		ft_ishex(char *s);
int		ft_ishexdigit(int c);
int		ft_ishash(int c, int cn);
int		ft_isformat(char *s);

#endif