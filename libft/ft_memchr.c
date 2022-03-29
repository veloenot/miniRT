/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:38:59 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 15:48:30 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_s;
	unsigned char	u_c;

	i = 0;
	u_s = (unsigned char *)s;
	u_c = (unsigned char)c;
	while (i < n)
	{
		if (u_s[i] == u_c)
			return (&u_s[i]);
		i++;
	}
	return (NULL);
}
