/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:00:12 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:01:01 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*u_b;

	i = 0;
	u_c = (unsigned char)c;
	u_b = (unsigned char *)b;
	while (i < len)
	{
		u_b[i] = u_c;
		i++;
	}
	return (b);
}
