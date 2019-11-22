/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:48:02 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/12 15:53:47 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	i = ft_strlen(s1);
	cpy = 0;
	if (!(cpy = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	cpy[i] = 0;
	while (i--)
		cpy[i] = s1[i];
	return (cpy);
}
