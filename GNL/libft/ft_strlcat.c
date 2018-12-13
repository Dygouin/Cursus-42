/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:07:47 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/15 00:06:33 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;
	size_t	i;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size < dest_size)
		return (size + src_size);
	while (src[i] && i + dest_size + 1 < size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[i + dest_size] = 0;
	return (dest_size + src_size);
}
