/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:34:47 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/24 23:38:17 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*node;
	t_list	*new_list;

	node = lst;
	tmp = ft_lstnew(f(node->content));
	if (tmp == NULL)
		return (NULL);
	new_list = tmp;
	tmp = tmp->next;
	node = node->next;
	while (node != NULL)
	{
		tmp = ft_lstnew(f(node->content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		node = node->next;
		tmp = tmp->next;
	}
	return (new_list);
}
