# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:47:24 by vlambert          #+#    #+#              #
#    Updated: 2019/02/05 15:36:55 by dygouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libftprintf.a
FLAGS=		-Wall -Wextra -Werror
SRC=		ft_printf.c arg.c width.c precision.c flags.c charfunctions.c \
			ft_ltoa_base.c ft_putfloat.c ft_putunicode.c tools.c \
			nbrfunction.c otherfunctions.c specifier.c \
			ft_atoi.c ft_bzero.c ft_fibonacci.c ft_is_lowerc.c ft_is_upperc.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
			ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
			ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_sqrt.c \
			ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
			ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			get_next_line.c
OBJ=		$(SRC:.c=.o)

OBJS=		$(addprefix objects/, $(OBJ))

all:		$(NAME)

$(NAME):	$(OBJS) ft_printf.h
	@ ar rc $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ printf "\033[38;2;0;255;0m"
	@ printf "libftprintf est compilée\n"
	@ printf "\033[0m"

$(OBJS):	$(SRC)
	@ mkdir -p objects
	@ gcc $(FLAGS) -c $?
	@ mv $(OBJ) objects/.

clean:
	@ rm -rf objects
	@ printf "\033[38;2;255;0;0m"
	@ printf "Les .o sont supprimés\n"
	@ printf "\033[0m"

fclean:		clean
	@ rm -rf $(NAME)
	@ printf "\033[38;2;255;0;0m"
	@ printf "$(NAME) est supprimée\n"
	@ printf "\033[0m"

re:			fclean all

.PHONY: clean fclean re all
