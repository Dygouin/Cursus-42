/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:42:00 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/13 20:42:20 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (len--)
	{
		if (src[i])
		{
			dst[j] = src[i];
			i++;
		}
		else
			dst[j] = 0;
		j++;
	}
	return (dst);
}
