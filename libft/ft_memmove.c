/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:36:47 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:48:35 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*u_src;
	unsigned char		*u_dst;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	u_src = (const unsigned char *)src;
	u_dst = (unsigned char *)dst;
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		i = len;
		while (i > 0)
		{
			u_dst[i - 1] = u_src[i - 1];
			i--;
		}
	}
	return (dst);
}
