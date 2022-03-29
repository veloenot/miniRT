/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:58:53 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 15:58:56 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_color(char **colors)
{
	while (*colors != NULL)
	{
		ft_str_is_valid_float(*colors, "Invalid color value\n");
		colors++;
	}
}

static char	*ft_get_color_err_str(char *elem, int color)
{
	char	*err;
	char	*tmp;

	if (color == 0)
		err = ft_strjoin("Invalid 'red' for ", elem);
	else if (color == 1)
		err = ft_strjoin("Invalid 'green' for ", elem);
	else
		err = ft_strjoin("Invalid 'blue' for ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, " color!\nUse in the range [0,255]\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

void	ft_check_color_value(int red, int green, int blue, char *elem)
{
	if (red < 0 || red > 255)
		ft_error(ft_get_color_err_str(elem, 0));
	else if (green < 0 || green > 255)
		ft_error(ft_get_color_err_str(elem, 1));
	else if (blue < 0 || blue > 255)
		ft_error(ft_get_color_err_str(elem, 2));
}
