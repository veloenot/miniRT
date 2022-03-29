/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:40:31 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:30:20 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*adr;

	i = 0;
	adr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			adr = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == c)
	{
		adr = (char *)&s[i];
	}
	return (adr);
}
