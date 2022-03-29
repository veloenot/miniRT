/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:08:29 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:08:30 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_ccalloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	num;

	i = 0;
	num = count * size;
	str = (char *)malloc(num);
	if (str == NULL)
		return (NULL);
	while (i < num)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_strlcpy_gnl(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*conc;
	size_t	i;
	size_t	j;

	conc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (conc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		conc[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		conc[i] = s2[j];
		i++;
		j++;
	}
	conc[i] = '\0';
	return (conc);
}
