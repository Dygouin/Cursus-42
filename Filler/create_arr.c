/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:46:51 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/18 18:49:01 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

void        create_arrays(t_filler *filler)
{
	int     size;

	if (filler->buffer_me)
		ft_memdel((void **)&filler->buffer_me);
	if (filler->buffer_enemy)
		ft_memdel((void **)&filler->buffer_enemy);
	size = filler->board.size;
	if (!(filler->buffer_me = ft_memalloc(size * sizeof(t_point))) || !(filler->buffer_enemy = ft_memalloc(size * sizeof(t_point))))
		exit(1);
	ft_bzero(filler->buffer_me, size * sizeof(t_point));
	ft_bzero(filler->buffer_enemy, size * sizeof(t_point));
}

void    fill_arrays(t_filler *filler)
{
	t_point p;

	create_arrays(filler);
	filler->me_counter = 0;
	filler->enemy_counter = 0;
	p.y = 0;
	while (p.y < filler->board.height)
	{
		p.x = 0;
		while (p.x < filler->board.width)
		{
			if (filler->board.tab[p.y][p.x] == filler->me.id)
				filler->buffer_me[filler->me_counter++] = p;
			else if (filler->board.tab[p.y][p.x] == filler->enemy.id)
				filler->buffer_enemy[filler->enemy_counter++] = p;
			p.x++;
		}
		p.y++;
	}
}

int     distance(t_point a, t_point b)
{
	return (ft_max(a.x, b.x) - ft_min(a.x, b.x) + ft_max(a.y, b.y) - ft_min(a.y, b.y)); 
}
