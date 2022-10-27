/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:02:05 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/22 20:26:10 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS		"Error: Incorrect number of arguments, expected 1"
# define ERR_OPEN		"Error: Can't open the file"
# define ERR_READ		"Error: Can't read the file"
# define ERR_LINE		"Error: The length of each row is not equal."
# define ERR_MEM		"Error: Can't allocate memory."
# define ERR_MAP		"Error: Can't draw map."
# define ERR_FORM		"Error: Incorrect format."
# define ERR_MLX		"Error: Can't initialize Minilibx."

void	error(char *s);
#endif