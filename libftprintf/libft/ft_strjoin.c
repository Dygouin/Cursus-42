/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:13:37 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/16 16:59:41 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
		s3[i++] = *(s2++);
	s3[i] = 0;
	return (s3);
}
