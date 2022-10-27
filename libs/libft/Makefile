# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 06:24:16 by tkhemniw          #+#    #+#              #
#    Updated: 2022/10/24 16:36:25 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f

SRCS_DIR	= ./srcs
INCS_DIR	= ./includes

SRCS 		= $(SRCS_DIR)/ft_strlcpy.c \
			  $(SRCS_DIR)/ft_split.c \
			  $(SRCS_DIR)/get_next_line.c \
			  $(SRCS_DIR)/get_next_line_utils.c \
			  $(SRCS_DIR)/ft_isnumeric.c \
			  $(SRCS_DIR)/ft_putendl_fd.c \
			  $(SRCS_DIR)/ft_putstr_fd.c \
			  $(SRCS_DIR)/ft_strlen.c \
			  $(SRCS_DIR)/ft_ishex.c

INCLUDES	= -I $(INCS_DIR)

OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -c

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all