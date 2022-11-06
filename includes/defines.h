/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:02:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/11/06 10:27:32 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WX 1300
# define WY 800
# define A -1
# define X 0
# define Y 1
# define Z 2
# define ISO 1
# define TOP 2
# define YES 1
# define NO 0
# define ROTZ -2
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x0
# define LIGHT_GRAY_PIXEL 0xAEAEAE
# define PEACH_PASTEL_PIXEL 0xFF7B74
# define DARK_GRAY_PIXEL 0x5A6776
# define MAX_SCALE 300000

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_gradient
{
	t_color	cdif;
	t_color	ori;
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
	int	color;
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
	int		cfrom;
	int		cto;
	t_point	**p;
}	t_map;

typedef struct s_transform
{
	int		istf;
	float	angx;
	float	angy;
	float	angz;
	int		iax;
	int		iay;
	int		tx;
	int		ty;
	int		ix;
	int		iy;
	float	scale;
	float	scalez;
	int		pov;
}	t_transform;

typedef struct s_event
{
	int	l_ck;
	int	r_ck;
	int	anim;
	int	menu;
}	t_event;

typedef struct s_background
{
	int	from;
	int	to;
}	t_background;

typedef struct s_mlx
{
	t_map			map;
	t_img			img;
	t_background	bg;
	t_event			e;
	t_transform		tf;
	void			*mlx_ptr;
	void			*win_ptr;
}	t_mlx;

# if __linux__
#  define KEY_ESC     0xff1b
#  define KEY_1       0x0031
#  define KEY_2       0x0032
#  define KEY_3       0x0033
#  define KEY_TAB     0xff09
#  define KEY_R		 0x0072
#  define KEY_Z		 0x007a
#  define KEY_X		 0x0078
#  define KEY_H		 0x0068
#  define KEY_SPACE	 0x0020
#  define LEFT_CK     1
#  define RIGHT_CK    3
#  define SC_UP       4
#  define SC_DOWN     5
#  define B_MOTMASK	8192L
#  define B_RELMASK	8L
#  define B_PRSMASK	4L
#  define K_RELMASK	2L

# elif __APPLE__
#  define KEY_ESC     53
#  define KEY_1       18
#  define KEY_2       19
#  define KEY_3       20
#  define KEY_TAB     48
#  define KEY_R		 15
#  define KEY_Z		 6
#  define KEY_X		 7
#  define KEY_SPACE	 49
#  define KEY_H		 4
#  define LEFT_CK     1
#  define RIGHT_CK    2
#  define SC_UP       5
#  define SC_DOWN     4
#  define B_MOTMASK		0
#  define B_RELMASK		0
#  define B_PRSMASK		0
#  define K_RELMASK		0

int	mlx_destroy_display(void *ptr);
# endif

#endif