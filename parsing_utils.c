/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:13:02 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:13:05 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_count_params(char **params)
{
	int	count;

	count = 0;
	while (*params != NULL)
	{
		count++;
		params++;
	}
	return (count);
}

long long	ft_atoll(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

float	ft_get_float(char *str)
{
	float	val;
	int		minus;

	minus = 0;
	if (*str == '-')
		minus = 1;
	val = ft_atoll(str);
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '\0')
		return (val);
	str++;
	if (val >= 0 && !minus)
		val = val + ft_atoll(str) * powf(10, (float)ft_strlen(str) * (-1));
	else
		val = (val * (-1) + ft_atoll(str) * \
			powf(10, (float)ft_strlen(str) * (-1))) * (-1);
	return (val);
}

void	ft_new_vector(t_vector **vector)
{
	*vector = (t_vector *)malloc(sizeof(t_vector));
	if (!(*vector))
		ft_error_sys_call();
	(*vector)->x = 0;
	(*vector)->y = 0;
	(*vector)->z = 0;
}

char	**ft_split_coord(char *param)
{
	char	**coord;

	coord = ft_split(param, ',');
	if (!coord)
		ft_error_sys_call();
	return (coord);
}
