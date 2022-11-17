# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 22:30:23 by ehoundey          #+#    #+#              #
#    Updated: 2022/02/28 22:30:24 by ehoundey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_memset.c			ft_bzero.c			ft_memcpy.c\
		ft_memccpy.c		ft_strmapi.c		ft_memchr.c\
		ft_memcmp.c			ft_strlen.c			ft_strlcpy.c\
		ft_strchr.c			ft_strrchr.c		ft_strnstr.c\
		ft_strncmp.c		ft_atoi.c			ft_itoa.c\
		ft_isalpha.c		ft_isdigit.c		ft_isalnum.c\
		ft_isascii.c		ft_isprint.c		ft_toupper.c\
		ft_tolower.c		ft_calloc.c			ft_strdup.c\
		ft_substr.c			ft_strjoin.c		ft_strlcat.c\
		ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c\
		ft_putnbr_fd.c		ft_strtrim.c		ft_putstr.c\
		ft_memmove.c		ft_split.c			ft_lstnew.c\
		ft_lstsize.c		ft_lstadd_front.c	ft_lstlast.c\
		ft_lstadd_back.c	get_next_line.c		get_next_line_utilis.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

HEADER = libft.h

CFLAGS =  -g -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
