/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:46:57 by dygouin           #+#    #+#             */
/*   Updated: 2019/11/18 18:48:55 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point     closest(t_filler filler)
{
	int     me_cur;
	int     enemy_cur;
	t_point tmp;
	t_point p;
	int     prev_dist;

	create_arrays(&filler);
	prev_dist = filler.board.size;
	me_cur = 0;
	while (me_cur < filler.me_counter)
	{
		enemy_cur = 0;
		while (enemy_cur < filler.enemy_counter)
		{
			if (distance(filler.buffer_me[me_cur], filler.buffer_enemy[enemy_cur]) <= prev_dist &&
					go_around(filler, filler.buffer_me[me_cur], &tmp))
			{
				p = tmp;
				prev_dist = distance(filler.buffer_me[me_cur], filler.buffer_enemy[enemy_cur]);
			}
			enemy_cur++;
		}
		me_cur++;
	}
	return (prev_dist == filler.board.size ? find_place(filler) : p);
}
