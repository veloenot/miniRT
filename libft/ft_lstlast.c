/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:13:33 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/24 22:13:48 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*new_lst;

	if (lst == NULL)
		return (NULL);
	new_lst = lst;
	while (new_lst->next != NULL)
	{
		new_lst = new_lst->next;
	}
	return (new_lst);
}
