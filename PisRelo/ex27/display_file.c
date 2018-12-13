/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:31:41 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/06 09:10:42 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *file_name)
{
	int		fd;
	char	ch;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	while (read(fd, &ch, 1))
		write(1, &ch, 1);
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac <= 1)
		write(2, "File name missing.\n", 19);
	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	if (ac == 2)
		ft_display_file(av[1]);
	return (0);
}
