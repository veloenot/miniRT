/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:59:05 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 15:59:07 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_str_is_valid_float(char *str, char *err_message)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '.')
		ft_error(err_message);
	while (*str != '.' && *str != '\0')
	{
		if (ft_isdigit(*str) != 1)
			ft_error(err_message);
		str++;
	}
	if (*str == '\0')
		return ;
	str++;
	if (*str == '\0')
		ft_error(err_message);
	while (*str != '\0')
	{
		if (ft_isdigit(*str) != 1)
			ft_error(err_message);
		str++;
	}
}

void	ft_str_is_valid_int(char *str, char *err_message)
{
	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) != 1)
			ft_error(err_message);
		str++;
	}
}

static void	ft_get_range_err_str(char **err, char *elem)
{
	char	*tmp;

	*err = ft_strjoin(elem, " ratio is greater than the permissible range\n");
	if (!(*err))
		ft_error_sys_call();
	tmp = *err;
	*err = ft_strjoin(*err, "Use in the range [0.0,1.0]\n");
	free(tmp);
	if (!(*err))
		ft_error_sys_call();
}

void	ft_check_ratio_range(float ratio, char *elem)
{
	char	*err;

	if (ratio < 0.0 || ratio > 1.0)
	{
		ft_get_range_err_str(&err, elem);
		ft_error(err);
	}
}
