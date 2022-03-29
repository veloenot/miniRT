/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:46:49 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/24 22:11:55 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		del(node->content);
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*lst = NULL;
}
