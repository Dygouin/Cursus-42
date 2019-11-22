/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:33:20 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/12 15:53:49 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i + count] != c && s[i + count])
				count++;
			if (!(split[j] = ft_strnew(count)))
				return (0);
			while (s[i] != c && s[i])
				split[j][k++] = s[i++];
			j++;
		}
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**split;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			count++;
		i++;
	}
	if (!(split = (char**)malloc((count + 1) * sizeof(char*))))
		return (NULL);
	split[count] = 0;
	if (!(ft_fill(s, c, split)))
		return (NULL);
	return (split);
}
