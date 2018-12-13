/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:22:26 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/15 00:00:54 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	size_t i;
	size_t j;

	i = 0;
	if (!small[0])
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (small[j] == big[i + j])
		{
			j++;
			if (!small[j])
				return ((char*)(big + i));
		}
		i++;
	}
	return (NULL);
}
