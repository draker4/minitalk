/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:24:44 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 16:55:43 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;

	begin = NULL;
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&begin, current);
		if (current == NULL)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (begin);
}
