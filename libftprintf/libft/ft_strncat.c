/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:41:31 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/13 20:41:49 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1);
	while (s2[j] && n--)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = 0;
	return (s1);
}