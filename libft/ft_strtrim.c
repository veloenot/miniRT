/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:30:37 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:36:40 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_first_trim(char const *s1, char const *set)
{
	int		j;
	int		count;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		count = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (count == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_end_trim(char const *s1, char const *set)
{
	int		j;
	int		count;
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0)
	{
		j = 0;
		count = 0;
		while (set[j] != '\0')
		{
			if (s1[len - 1] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (count == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	i;
	size_t	t;
	size_t	len;

	i = ft_first_trim(s1, set);
	len = ft_end_trim(s1, set);
	if (len < i)
		return (ft_strdup(""));
	strim = (char *)malloc(sizeof(char) * (len - i + 1));
	if (strim == NULL)
		return (NULL);
	t = 0;
	while (i < len)
	{
		strim[t] = s1[i];
		t++;
		i++;
	}
	strim[t] = '\0';
	return (strim);
}
