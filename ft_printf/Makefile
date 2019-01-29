# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:47:24 by vlambert          #+#    #+#              #
#    Updated: 2019/01/29 09:40:42 by vlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libftprintf.a
FLAGS=		-Wall -Wextra -Werror
SRC=		ft_printf.c arg.c width.c precision.c flags.c charfunctions.c \
			ft_ltoa_base.c ft_putfloat.c ft_putunicode.c tools.c \
			nbrfunction.c otherfunctions.c specifier.c
OBJ=		*.o libft/*.o

all:		$(NAME)

$(NAME):	$(SRC) ft_printf.h
	@ make --silent $(OBJ)
	@ make --silent -C libft/
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "libftprintf est compilée"

$(OBJ):		$(SRC)
	gcc $(FLAGS) -c $?

clean:
	@ make -C libft/ clean
	@ rm -rf $(OBJ)
	@ echo "Les .o sont supprimés"

fclean:		clean
	@ make -C libft/ fclean
	@ rm -rf $(NAME)
	@ echo "$(NAME) est supprimée"

re:			fclean all

.PHONY: clean fclean re
