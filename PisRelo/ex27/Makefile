# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 08:31:38 by dygouin           #+#    #+#              #
#    Updated: 2018/11/06 09:03:42 by dygouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_display_file
FLAGS=-Wall -Wextra -Werror

all: ft_display_file

ft_display_file:
		gcc $(FLAGS) display_file.c -o$(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)

re: fclean all
