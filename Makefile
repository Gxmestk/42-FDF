# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 06:51:52 by tkhemniw          #+#    #+#              #
#    Updated: 2022/11/06 06:25:19 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Defaults
NAME				= fdf
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= /bin/rm -f

#Directories
INCS_DIR			= ./includes
SRC_DIR				= ./srcs
LIBFT_DIR			= ./libs/libft
MINILIBX_LINUX_DIR	= ./libs/minilibx-linux
MINILIBX_MACOS_DIR	= ./libs/minilibx_macos

#Includes
INCLUDES 			= -I $(INCS_DIR)									\
					  -I $(LIBFT_DIR)/includes

#Libraries
LIBS				= -L $(LIBFT_DIR) -lft

#Mac or Linux
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX_DIR		= $(MINILIBX_LINUX_DIR)
	MINILIBX_CC_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	MINILIBX_OBJ_FLAG 	= $(INCLUDES) \
						  -I/usr/include \
						  -I$(MLX_DIR)
	LIBS		+= -L /usr/lib \
					-L $(MLX_DIR)
else
	MLX_DIR		= $(MINILIBX_MACOS_DIR)
	MINILIBX_CC_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit
	MINILIBX_OBJ_FLAG 	= $(INCLUDES) \
						-I$(MLX_DIR)

	LIBS			+= -L $(MLX_DIR)

endif

#Source files
SRCS				= $(SRC_DIR)/fdf.c \
					  $(SRC_DIR)/map_load.c \
					  $(SRC_DIR)/mlx_optimize.c \
					  $(SRC_DIR)/utils.c \
					  $(SRC_DIR)/errors.c \
					  $(SRC_DIR)/color.c \
					  $(SRC_DIR)/map_draw.c \
					  $(SRC_DIR)/event.c \
					  $(SRC_DIR)/rotate.c \
					  $(SRC_DIR)/translate.c \
					  $(SRC_DIR)/zoom.c \
					  $(SRC_DIR)/atoi_form.c \
					  $(SRC_DIR)/transform.c \
					  $(SRC_DIR)/mouse.c \
					  $(SRC_DIR)/key.c

#Object files 
OBJS 				= $(SRCS:%.c=%.o)

#Command

#Make defaults
all:				$(NAME)

#Make ./fdf
$(NAME):			$(OBJS) libs
						$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MINILIBX_CC_FLAGS) -o $(NAME)

bonus:				all

#Make .a
libs:		
			make -C $(LIBFT_DIR)
			make -C $(MLX_DIR)

#.c to .o
.c.o:
					$(CC) $(CFLAGS) $(MINILIBX_OBJ_FLAG) $< -o $@ -c

#Cleaner
clean:
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) -r $(OBJS)

fclean:				clean
					make fclean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(NAME)

#Restart
re:					fclean all

code:				
					code $(SRCS)

codeh:
					code $(INCS_DIR)/*

debug:				$(OBJS) libs
						$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MINILIBX_CC_FLAGS) -g -o $(NAME)

norm:
					clear && norminette $(SRC_DIR) $(LIBFT_DIR) | grep "Error"
normh:
					clear &&norminette -R CheckHeader $(SRC_DIR) $(LIBFT_DIR) | grep "Error"
normf:
					clear && norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(LIBFT_DIR) | grep "Error"

#.PHONY
.PHONY:				all bonus libs clean fclean re code codeh norm normh normf debug
	