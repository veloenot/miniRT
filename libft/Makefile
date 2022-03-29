# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 14:08:35 by tmillenn          #+#    #+#              #
#    Updated: 2022/01/10 18:05:29 by jkassand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c 

SRCSBONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

OBJSBONUS	= $(SRCSBONUS:.c=.o)

NAME		= libft.a

CC		= gcc

RM		= rm -f

%.o: %.c	Makefile libft.h
			$(CC) $(CFLAGS) -c $< -o $@

CFLAGS		= -Wall -Werror -Wextra


$(NAME):	$(OBJS) 
			ar rsc $(NAME) $? 

all:		$(NAME)

bonus: 		$(OBJS) $(OBJSBONUS)
			ar rc $(NAME) $(OBJS) $(OBJSBONUS)

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

.PHONY:		all bonus clean fclean re

