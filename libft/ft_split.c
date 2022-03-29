/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:20:53 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 17:24:18 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
			{
				count++;
				break ;
			}
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_malloc_str(int j, char **arr, int count_char)
{
	arr[j] = (char *)malloc(sizeof(char) * count_char + 1);
	if (arr[j] == NULL)
	{
		while (j > 0)
		{
			free(arr[j - 1]);
			j--;
		}
		free(arr);
		return (NULL);
	}
	return (arr);
}

static int	ft_count_char(char const *s, char c, int i)
{
	int	count_char;

	count_char = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count_char++;
		i++;
	}
	return (count_char);
}

static char	**ft_str_malloc(char const *s, char c, char **arr, int i)
{
	int	j;
	int	t;
	int	count_char;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			count_char = ft_count_char(s, c, i);
			i = i + count_char;
			arr = ft_malloc_str(j, arr, count_char);
			if (arr == NULL)
				return (NULL);
			t = 0;
			while (i - count_char < i)
				arr[j][t++] = s[i - count_char--];
			arr[j][t] = '\0';
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = ft_str_malloc(s, c, arr, i);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
