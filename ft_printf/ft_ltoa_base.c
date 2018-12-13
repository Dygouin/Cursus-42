/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:59:54 by dygouin           #+#    #+#             */
/*   Updated: 2018/12/13 17:31:39 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(long long value, char base)
{
	int					i;

	i = 1;
	if (value < 0 && base == 10)
	{
		value = value * -1;
		i = 2;
	}
	while ((unsigned long long)value >= (unsigned long long)base)
	{
		value = value / base;
		i++;
	}
	return (i);
}

void	ft_filltab(char tab[17], char maj)
{
	int					i;
	char				j;
	char				k;

	i = 0;
	j = '0';
	k = 'a';
	while (j != ':')
		tab[i++] = j++;
	while (maj == 0 && k != 'g')
		tab[i++] = k++;
	while (maj == 1 && k - 32 != 'G')
		tab[i++] = (k++ - 32);
}

unsigned long long		ft_init(char base, long long value, char *sol)
{
	unsigned long long	val;

	if (value < 0 && base == 10)
	{
		val = value * -1;
		sol[0] = '-';
	}
	else if (value < 0)
		val = (unsigned int)value;
	else
		val = value;
	return (val);
}

void	ft_ltoa_base(long long value, char base, char maj)
{
	char				tab[17];
	int					len;
	char				*sol;
	unsigned long long	val;

	tab[16] = '\0';
	if (base > 16 || base <= 1)
		return ;
	ft_filltab(tab, maj);
	len = ft_getlen(value, base);
	if (!(sol = ft_strnew(len)))
		return ;
	val = ft_init(base, value, sol);
	while (len-- > 0 && sol[len] != '-')
	{
		sol[len] = tab[val % base];
		val /= base;
	}
	ft_putstr_fd(sol, 1);
	ft_strdel(&sol);
}

int		main(int ac, char **av)
{
	double	a = -128;

	ft_ltoa_base(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]));
	printf("\n%i\n", a);
	return (0);
}
