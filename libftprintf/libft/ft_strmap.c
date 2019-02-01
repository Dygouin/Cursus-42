/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:14:32 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/14 23:14:47 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*s2;
	size_t	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (!(s2 = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (*s)
		s2[i++] = (*f)(*(s++));
	return (s2);
}
