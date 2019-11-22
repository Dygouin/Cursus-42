# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dygouin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 18:47:42 by dygouin           #+#    #+#              #
#    Updated: 2019/11/19 18:43:01 by dygouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	dygouin.filler

LIB_DIR 	:= ./libft

LIB			:= ./libft/libftprintf.a

INC			:= ./filler.h

LIB_INC		:= ./libft/libft.h

SRC			:=	filler.c \
				create_arr.c \
				closest.c \
				read_free.c \
				alg.c \
				ft_max.c \
				ft_min.c

OBJ			:=	$(SRC:.c=.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror


all: $(LIB) $(NAME)
	make -C $(LIB_DIR) re

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -L $(LIB_DIR) ./libft/libftprintf.a $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

superj:
	./resources/filler_vm -f resources/maps/map01 -p1 dygouin.filler -p2 resources/players/superjeannot.filler

superjj:
	./resources/filler_vm -f resources/maps/map01 -p1 resources/players/superjeannot.filler -p2 resources/players/superjeannot.filler

.PHONY: all clean fclean re superj
