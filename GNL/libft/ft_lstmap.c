/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <dygouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:11:02 by dygouin           #+#    #+#             */
/*   Updated: 2018/11/12 15:53:34 by dygouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*alst;

	if (!lst)
		return (NULL);
	alst = f(lst);
	new = alst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(alst->next = f(lst)))
		{
			free(alst->next);
			return (NULL);
		}
		alst = alst->next;
	}
	return (new);
}
