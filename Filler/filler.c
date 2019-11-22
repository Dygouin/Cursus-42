/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:46:25 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/19 16:49:20 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void			init(t_filler *filler)
{
	t_point		p;

	p.y = 0;
	while (p.y < filler->board.height)
	{
		p.x = 0;
		while (p.x < filler->board.width)
		{
			if (filler->board.tab[p.y][p.x] == filler->me.id)
				filler->me.start = p;
			else if (filler->board.tab[p.y][p.x] == filler->enemy.id)
				filler->enemy.start = p;
			p.x++;
		}
		p.y++;
	}
	filler->target.y = (filler->enemy.start.y - filler->me.start.y < 0 ?
			0 : filler->board.height - 1);
	filler->target.x = (filler->enemy.start.x - filler->me.start.x < 0 ?
			0 : filler->board.width - 1);
	filler->initialized = 1;
}

void			filler_loop(t_filler filler)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue;
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			read_tab(line, 4, &filler.board);
			if (!filler.initialized)
				init(&filler);
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_tab(line, 0, &filler.piece);
			place(filler);
		}
		ft_strdel(&line);
	}
}

int				main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	filler.initialized = 0;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
			!ft_strncmp(line, "$$$ exec p", 9) &&
			(line[10] == '1' || line[10] == '2'))
	{
		filler.me.id = (line[10] == '1' ? 'O' : 'X');
		filler.enemy.id = (line[10] == '1' ? 'X' : 'O');
		ft_strdel(&line);
		filler_loop(filler);
	}
	else
		return (1);
	return (0);
}
