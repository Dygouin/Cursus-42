/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:47:35 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/19 12:47:38 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_player
{
	int				id;
	t_point			start;
}					t_player;

typedef struct		s_boardpiece
{
	int				width;
	int				height;
	int				size;
	char			**tab;
}					t_boardpiece;

typedef struct		s_filler
{
	int				initialized;
	t_player		me;
	t_player		enemy;
	t_point			target;
	t_boardpiece	board;
	t_boardpiece	piece;
	t_point			*buffer_me;
	int				me_counter;
	t_point			*buffer_enemy;
	int				enemy_counter;
}					t_filler;

void				free_boardpiece(t_boardpiece *boardpiece, int off);
void				read_tab(char *line, int off, t_boardpiece *boardpiece);
void				init(t_filler *filler);
void				filler_loop(t_filler filler);
int					valid_pos(t_filler filler, t_point p);
int					go_around(t_filler filler, t_point p, t_point *res);
void				place(t_filler filler);
int					try(t_filler filler, t_point p);
t_point				find_place(t_filler filler);
t_point				closest(t_filler filler);
void				create_arrays(t_filler *filler);
void				fill_arrays(t_filler *filler);
int					distance(t_point a, t_point b);
void				filler_loop(t_filler filler);
void				init(t_filler *filler);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

#endif
