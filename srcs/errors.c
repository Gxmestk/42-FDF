/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:23:36 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/22 16:22:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "errors.h"
#include "libft.h"

void	error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, STDERR_FILENO);
	else
		perror(s);
	exit(1);
}
