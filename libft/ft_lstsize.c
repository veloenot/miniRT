/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:25:46 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/24 22:15:20 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*new_lst;

	if (lst == NULL)
		return (0);
	count = 1;
	new_lst = lst;
	while (new_lst->next != NULL)
	{
		new_lst = new_lst->next;
		count++;
	}
	return (count);
}
