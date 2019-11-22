/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:04 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/18 18:48:48 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void        free_boardpiece(t_boardpiece *boardpiece, int off)
{
	int         i;
	char        *str;

	if (!boardpiece->tab)
		return ;
	i = 0;
	while (i < boardpiece->height)
	{
		str = boardpiece->tab[i] - off;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&boardpiece->tab);
}

void        read_tab(char *line, int off, t_boardpiece *boardpiece)
{
	int         i;

	free_boardpiece(boardpiece, off);
	line = ft_strchr(line, ' ') + 1;
	boardpiece->height = ft_atoi(line);
	boardpiece->width = ft_atoi(ft_strchr(line, ' '));
	boardpiece->size = boardpiece->height * boardpiece->width;
	if (off)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	boardpiece->tab = ft_memalloc(boardpiece->height * sizeof(char *));
	i = 0;
	while (i < boardpiece->height)
	{
		get_next_line(0, &line);
		boardpiece->tab[i] = line + off;
		i++;
	}
}
