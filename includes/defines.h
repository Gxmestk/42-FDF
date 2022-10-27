/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:02:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/26 22:20:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WX 1300
# define WY 800
# define X 0
# define Y 1
# define Z 2
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF

typedef	struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_gradient
{
	t_color	cdif;
	t_color ori;
	int		t;
}	t_gradient;


typedef struct s_slope
{
	int	dx;
	int	dy;
	int	p;
}	t_slope;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	coord[3];
	int		color;
}	t_point;

typedef struct s_line
{
	char	*line;
	char	**splited;
	int		wc;
}	t_line;

typedef struct s_map
{
	int		fd;
	int		mapx;
	int		mapy;
	t_point	**p;
	float	scale;
}	t_map;

typedef struct s_mlx
{
	t_map	map;
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

#endif