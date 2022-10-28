/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:02:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/28 14:06:36 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WX 1300
# define WY 800
# define X 0
# define Y 1
# define Z 2
# define ISO 1
# define PAR 2
# define YES 1
# define NO 0
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x0
# define LIGHT_GRAY_PIXEL 0xAEAEAE
# define PEACH_PASTEL_PIXEL 0xFF7B74
# define DARK_GRAY_PIXEL 0x5A6776
# define APLLE 69
# define LINUX 96

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

typedef struct s_transform
{
	int		istf;
	float	angx;
	float	angy;
	float	angz;
	int		tx;
	int		ty;
	int		tz;
	int		pov;
}	t_transform;

typedef struct s_mlx
{
	t_map		map;
	t_img		img;
	int			bg_color_f;
	int			bg_color_t;
	t_transform	tf;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_mlx;

#endif