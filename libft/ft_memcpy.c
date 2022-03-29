/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:50:50 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 15:52:08 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*u_src;
	unsigned char		*u_dst;

	i = 0;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	u_src = (const unsigned char *)src;
	u_dst = (unsigned char *)dst;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	return (dst);
}
