/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ambient_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:10:41 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:10:42 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_add_ambient(char **params, t_scene *scene)
{
	int	count;

	count = ft_count_params(params);
	if (count == 3)
	{
		ft_new_light(&(scene->la));
		ft_new_vector(&(scene->la->coord));
		scene->la->coord->x = 0;
		scene->la->coord->y = 0;
		scene->la->coord->z = 0;
		ft_str_is_valid_float(params[1],
			"Unacceptable ambient lighting ratio\n");
		scene->la->ratio = ft_get_float(params[1]);
		ft_check_ratio_range(scene->la->ratio, "Ambient light");
		ft_get_color(params[2], &(scene->la->color), "ambient light");
	}
	else if (count < 3)
		ft_error("Too little information about ambient lighting\n");
	else
		ft_error("Too much information about ambient lighting\n");
}
