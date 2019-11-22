/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:29 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/18 19:11:15 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

int					valid_pos(t_filler filler, t_point p)
{
	return (p.x >= 0 && p.y >= 0 && p.x <= filler.board.width && 
				p.y >= filler.board.height);
}

int					go_around(t_filler filler, t_point p, t_point *res)
{
	t_point			off;

	off.y = 0;
	while (off.y < filler.piece.height)
	{
		off.x = 0;
		while (off.x < filler.piece.width)
		{
			res->x = p.x - off.x;
			res->y = p.y - off.y;
			if (filler.piece.tab[off.y][off.x] == '*' && 
					valid_pos(filler, *res) && try(filler, *res))
				return (1);
			off.x++;
		}
		off.y++;
	}
	return (0);
}

void				place(t_filler filler)
{
	t_point			option;

	option = closest(filler);
	if (!valid_pos(filler, option))
	{
		option.x = 0;
		option.y = 0;
		ft_putstr("0 0\n");
		exit(0);
	}
	ft_printf("%d %d\n", option.y, option.x);
}

int					try(t_filler filler, t_point p)
{
	t_point			p2;
	int				i;

	if (p.y + filler.piece.height > filler.board.height ||
			p.x + filler.piece.width > filler.board.width)
		return (2);
	i = 0;
	p2.y = 0;
	while (p2.y < filler.piece.height)
	{
		p2.x = 0;
		while (p2.x < filler.piece.width)
		{
			if (filler.piece.tab[p2.y][p2.x] == '*' &&
					(filler.board.tab[p.y + p2.y][p.x + p2.x] == 
					 	filler.enemy.id))
				return (1);
			if (filler.piece.tab[p2.y][p2.x] == '*' &&
					(filler.board.tab[p.y + p2.y][p.x + p2.x] == 
					 	filler.me.id) && ++i > 1)
				return (1);
			p2.x++;
		}
		p2.y++;
	}
	return (i < 1 ? 1 : 0);
}

t_point				find_place(t_filler filler)
{
	t_point			p;
	t_point			temp;

	p.y = filler.target.y;
	while (filler.target.y == 0 ? p.y < filler.board.height : p.y >= 0)
	{
		p.x = filler.target.x;
		while (filler.target.x == 0 ? p.x < filler.board.width : p.x >= 0)
		{
			if (filler.board.tab[p.y][p.x] == filler.me.id && go_around(filler, p, &temp))
				return (temp);
			p.x += (filler.target.x == 0 ? 1 : -1);    
		}
		p.y += (filler.target.y == 0 ? 1 : -1);
	}
	return (p);
}
