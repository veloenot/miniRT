/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:59:58 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:00:00 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*ft_get_color_err_little(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too little information about ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, " color\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

static char	*ft_get_color_err_much(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too much information about ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, " color\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

static void	ft_set_colors(char **colors, float *red, float *green, float *blue)
{
	*red = ft_get_float(colors[0]);
	*green = ft_get_float(colors[1]);
	*blue = ft_get_float(colors[2]);
}

void	ft_get_color(char *color_params, t_vector **color, char *name_elem)
{
	char	**colors;
	int		count;

	colors = ft_split(color_params, ',');
	if (!colors)
		ft_error_sys_call();
	count = ft_count_params(colors);
	if (count == 3)
	{
		ft_check_color(colors);
		ft_new_vector(color);
		ft_set_colors(colors, &((*color)->x), &((*color)->y), &((*color)->z));
		ft_check_color_value((*color)->x, (*color)->y, (*color)->z, name_elem);
	}
	else if (count < 3)
		ft_error(ft_get_color_err_little(name_elem));
	else
		ft_error(ft_get_color_err_much(name_elem));
	ft_free_arr(colors);
}
