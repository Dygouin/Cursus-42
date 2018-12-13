/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:16:19 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/14 23:21:48 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!small[0])
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (small[j] == big[i + j])
		{
			if (i + j == len)
				return (NULL);
			j++;
			if (!small[j])
				return ((char*)(big + i));
		}
		i++;
	}
	return (NULL);
}
