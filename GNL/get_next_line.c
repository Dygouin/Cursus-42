/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:20:39 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/27 21:22:14 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_line_before_n(char **last_line_read)
{
	char	*str;
	size_t	i;
	char	*line;

	i = 0;
	while ((*last_line_read)[i] != '\n' && (*last_line_read)[i] != '\0')
		i++;
	line = ft_strsub(*last_line_read, 0, i);
	str = *last_line_read;
	if ((*last_line_read)[i] == '\0')
		*last_line_read = ft_strnew(0);
	else
		*last_line_read = ft_strdup(*last_line_read + i + 1);
	free(str);
	return (line);
}

t_list		*get_valid_list(t_list **list_save, int fd)
{
	t_list	*tmp;
	t_list	*first;

	if (*list_save == NULL)
		*list_save = (t_list*)ft_memalloc(sizeof(t_list));
	first = *list_save;
	while (list_save)
	{
		if (((int)(*list_save)->content_size) == fd && (*list_save)->content)
		{
			tmp = *list_save;
			*list_save = first;
			return (tmp);
		}
		if ((*list_save)->next)
			*list_save = (*list_save)->next;
		else
			break ;
	}
	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	tmp->content_size = fd;
	tmp->content = ft_memalloc(sizeof(char) * 1);
	(*list_save)->next = tmp;
	*list_save = first;
	return (tmp);
}

int			ft_read_file(char **content, t_list *list)
{
	char	*buf;
	int		size;
	char	*to_free;

	buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while ((size = read(list->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		to_free = *content;
		*content = ft_strjoin(*content, buf);
		ft_memdel((void*)&to_free);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	ft_memdel((void*)&buf);
	return (size);
}

int			get_next_line(const int fd, char **line)
{
	static	t_list	*list_save;
	t_list			*list;
	int				amount_read;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	list = get_valid_list(&list_save, fd);
	if (!(ft_strchr(list->content, '\n')))
	{
		if ((amount_read = ft_read_file((char**)(&list->content), list)) == -1
				|| (amount_read == 0 && ft_strlen(list->content) == 0))
		{
			*line = ft_strnew(0);
			return (amount_read);
		}
	}
	*line = get_line_before_n((char**)(&list->content));
	return (1);
}
