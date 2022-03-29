/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:00:18 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 15:46:54 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*u_dst;
	const unsigned char	*u_src;
	unsigned char		u_c;

	i = 0;
	u_c = (unsigned char)c;
	u_src = (const unsigned char *)src;
	u_dst = (unsigned char *)dst;
	while (i < n && u_src[i] != u_c)
	{
		u_dst[i] = u_src[i];
		i++;
	}
	if (u_src[i] == u_c && i < n)
	{
		u_dst[i] = u_src[i];
		return (&u_dst[i + 1]);
	}
	return (NULL);
}
