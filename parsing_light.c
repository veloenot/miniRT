/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:17 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:19 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_new_light(t_light **lt)
{
	*lt = (t_light *)malloc(sizeof(t_light));
	if (!(*lt))
		ft_error_sys_call();
	(*lt)->coord = NULL;
	(*lt)->color = NULL;
	(*lt)->ratio = 0;
}

static void	ft_get_light_brightness_ratio(char *param_ratio, t_scene *scene)
{
	ft_str_is_valid_float(param_ratio, "Unacceptable light brightness ratio\n");
	scene->lt->ratio = ft_get_float(param_ratio);
	ft_check_ratio_range(scene->lt->ratio, "Light brightness");
}

void	ft_add_light(char **params, t_scene *scene)
{
	int	count;

	count = ft_count_params(params);
	if (count == 3)
	{
		ft_new_light(&(scene->lt));
		ft_get_coord(params[1], &(scene->lt->coord), "light");
		ft_get_light_brightness_ratio(params[2], scene);
		ft_get_color("255,255,255", &(scene->lt->color), "light");
	}
	else if (count < 3)
		ft_error("Too little information about light\n");
	else
		ft_error("Too much information about light\n");
}
