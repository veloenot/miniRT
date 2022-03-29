/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:25:03 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:28:25 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	i = 0;
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while ((u_s1[i] != '\0' && i < n) || (u_s2[i] != '\0' && i < n))
	{
		if (u_s1[i] == u_s2[i])
			i++;
		else
		{
			if (u_s1[i] > u_s2[i])
				return (1);
			else if (u_s1[i] < u_s2[i])
				return (-1);
		}
	}
	return (0);
}
