/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 03:50:26 by marvin            #+#    #+#             */
/*   Updated: 2019/01/29 03:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int ac, char **av)
{
    int i = 1;
    int    t[32] = {0};
    int     j = 1;

    if (ac == 1)
    {
        write(1, "usage:asdfasdfasdfasef", 34);
        return (0);
    }
    while (i < ac)
    {
        j = 1;
        if (av[i][0] == '-')
        {
            while (av[i][j] && av[i][j] >= 'a' && av[i][j] <= 'z')
            {
                if (av[i][j] == 'h')
                {
                    write(1, "usage:asdjfhalsidhfoailsdhfoiahsdf", 34);
                    return (0);
                }
                t['z' - av[i][j] + 6] = 1;
                j++;
            }
            if (av[i][j])
            {
                write(1, "Invalid Option\n", 16);
                return (0);
            }
        }
        i++;
    }
    i = 0;
    while (i < 32)
    {
        t[i] = t[i] + '0';
        write(1, &t[i], 1);
        i++;
        if (i == 32)
            write(1, "\n", 1);
        if (i % 8 == 0 && i != 32)
            write(1, ' ', 1);
        }
        return (0);
}
