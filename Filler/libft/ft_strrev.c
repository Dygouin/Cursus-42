/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:34:03 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/12 15:53:48 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	count;
	size_t	i;
	char	temp;

	count = 0;
	while (str[count] != '\0')
		count++;
	if (str)
	{
		i = 0;
		while (i < count)
		{
			temp = str[i];
			str[i] = str[count - 1];
			str[count - 1] = temp;
			i++;
			count--;
		}
	}
	return (str);
}
