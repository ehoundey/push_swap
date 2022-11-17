# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 22:32:10 by ehoundey          #+#    #+#              #
#    Updated: 2022/02/28 22:32:11 by ehoundey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

S_DIR = ./srcs

B_DIR = ./bonus

I_DIR = ./includes

SRCS = 	$(S_DIR)/push_swap.c\
		$(S_DIR)/lists.c			$(S_DIR)/fill_order.c\
		$(S_DIR)/sort_data.c		$(S_DIR)/check_if_correct.c\
		$(S_DIR)/prov_markup.c		$(S_DIR)/instructions.c \
		$(S_DIR)/sort_big_2.c		$(S_DIR)/sort_big.c\
		$(S_DIR)/num_prov.c			$(S_DIR)/num_to_move_back.c\
		$(S_DIR)/fill_a.c			$(S_DIR)/instructions2.c\
		$(S_DIR)/new_sort_data.c	$(S_DIR)/utilis.c\
		$(S_DIR)/if_num_correct.c

BSRCS = $(B_DIR)/checker.c\
		$(B_DIR)/for_checker.c		$(S_DIR)/utilis.c\
		$(S_DIR)/fill_order.c		$(S_DIR)/check_if_correct.c\
		$(S_DIR)/lists.c			$(S_DIR)/if_num_correct.c\
		$(S_DIR)/instructions.c		$(S_DIR)/instructions2.c\
		$(S_DIR)/sort_big.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

HEADER = $(I_DIR)/push_swap.h

CC = gcc

RM = rm -f

CFLAGS = -g -Wall -Wextra -Werror -I $(I_DIR)

LIB = libft/libft.a

all: $(NAME)

bonus: $(BNAME)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME)

$(BNAME): $(BOBJS) $(LIB)
		$(CC) $(CFLAGS) $(LIB) $(BOBJS) -o $(BNAME)

$(LIB):
		make -C libft

clean:
		make clean -C libft
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME) $(BNAME) $(LIB)

re:		fclean all

.PHONY:	all clean fclean re bonus

