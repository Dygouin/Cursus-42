/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:15:25 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/12 15:53:31 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t				len;
	unsigned int		num;
	char				*str;

	len = get_len(n);
	num = n;
	if (n < 0)
	{
		len++;
		num = -n;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = num % 10 + '0';
	while (num /= 10)
		str[--len] = num % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
