/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:18:59 by dygouin           #+#    #+#             */
/*   Updated: 2019/01/25 19:01:55 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char			*ft_putunicode(t_options options, wint_t num)
{
	char	*str;

	(void)options;
	str = NULL;
	if (!(str = ft_strnew(4)))
		return (NULL);
	if (num > 0 && num <= 0x7f)
		str[0] = (char)(num & 0x7f);
	else if (num <= 0x7ff)
	{
		str[1] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[0] = ((char)num | 0xC0) & 0xdf;
	}
	else if (num <= 0xffff)
	{
		if (num >= 0xd800 && num <= 0xdfff)
			return (NULL);
		str[2] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[1] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[0] = ((char)num | 0xe0) & 0xef;
	}
	else if (num <= 0x10ffff)
	{
		if (num > 0x2ffff && num < 0xe0000)
			return (ft_strdup(""));
		str[3] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[2] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[1] = ((char)num | 0x80) & 0xbf;
		num = num >> 6;
		str[0] = ((char)num | 0xf0) & 0xf7;
	}
	return (str);
}
