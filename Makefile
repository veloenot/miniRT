# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkassand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 23:48:20 by jkassand          #+#    #+#              #
#    Updated: 2022/01/24 20:41:46 by jkassand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= minirt.c get_pl_color.c get_sp_color.c ray_tracing.c \
			  sp_pl_cy_shad_int.c turn.c mouse_key.c new_objects.c \
			  vec_utils.c \
			  check_color_value.c check_valid_value.c errors.c free.c \
			  get_color.c get_coord.c get_next_line.c get_next_line_utils.c \
			  get_norm_vector.c parsing.c parsing_ambient_light.c \
			  parsing_camera.c parsing_cylinder.c parsing_light.c \
			  parsing_plane.c parsing_read_file.c parsing_sphere.c \
			  parsing_utils.c get_cy_color.c cy_sh_sp_pl.c parsing_utils2.c \
			  shadow_sp.c move.c

OBJS		= $(SRCS:.c=.o)

LIBFT_LIB	= libft/libft.a

LIB			= -L libft -lft -lmlx

NAME		= miniRT

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

FWFLAGS		= -framework OpenGL -framework AppKit

RM			= rm -f

%.o: %.c	Makefile minirt.h
			$(CC) $(CFLAGS) -c $< -o $@ -Ofast

$(NAME):	$(LIBFT_LIB) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(FWFLAGS)

all:		$(NAME)

$(LIBFT_LIB):	tools ;

tools:
			make -C libft

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C libft
			$(RM) $(NAME)

re:			fclean all

bonus:		$(NAME)

.PHONY:		all clean fclean re bonus
