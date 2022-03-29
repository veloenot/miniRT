/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:47:20 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 15:44:51 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int				count;
	unsigned int	u_n;

	count = 0;
	if (n < 0)
	{
		u_n = n * (-1);
		count++;
	}
	else
		u_n = n;
	if (u_n == 0)
		count++;
	while (u_n > 0)
	{
		u_n = u_n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	u_n;
	int				count;

	count = ft_count(n);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);
	num[count] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		u_n = n * (-1);
	}
	else
		u_n = n;
	if (u_n == 0)
		num[count - 1] = '0';
	while (u_n > 0)
	{
		num[count - 1] = u_n % 10 + '0';
		u_n = u_n / 10;
		count--;
	}
	return (num);
}
