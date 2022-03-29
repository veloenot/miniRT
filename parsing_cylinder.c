/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:06 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:07 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_new_cylinder(t_cylinder **cylinder)
{
	*cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!(*cylinder))
		ft_error_sys_call();
	(*cylinder)->coord = NULL;
	(*cylinder)->dir = NULL;
	(*cylinder)->r = 0;
	(*cylinder)->h = 0;
	(*cylinder)->color = NULL;
	(*cylinder)->next = NULL;
}

static void	ft_add_back_cylinder(t_cylinder **cylinder, t_cylinder *new)
{
	t_cylinder	*tmp;

	tmp = *cylinder;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static void	ft_get_cylinder_radius(char *diameter, t_cylinder **cylinder)
{
	ft_str_is_valid_float(diameter, "Unacceptable cylinder diameter\n");
	(*cylinder)->r = ft_get_float(diameter) * 0.5;
	if ((*cylinder)->r < 0)
		ft_error("Invalid cylinder diameter!\nUse d > 0\n");
}

static void	ft_get_cylinder_height(char *height, t_cylinder **cylinder)
{
	ft_str_is_valid_float(height, "Unacceptable cylinder height\n");
	(*cylinder)->h = ft_get_float(height);
	if ((*cylinder)->h < 0)
		ft_error("Invalid cylinder height!\nUse h > 0\n");
}

void	ft_add_cylinder(char **params, t_scene *scene)
{
	int			count;
	t_cylinder	*cylinder;
	t_cylinder	*tmp;

	count = ft_count_params(params);
	if (count == 6)
	{
		ft_new_cylinder(&cylinder);
		if (!scene->cy)
			scene->cy = cylinder;
		else
			ft_add_back_cylinder(&(scene->cy), cylinder);
		tmp = scene->cy;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_get_coord(params[1], &(tmp->coord), "cylinder");
		ft_get_norm_vector(params[2], &(tmp->dir), "cylinder");
		ft_get_cylinder_radius(params[3], &tmp);
		ft_get_cylinder_height(params[4], &tmp);
		ft_get_color(params[5], &(tmp->color), "cylinder");
	}
	else if (count < 6)
		ft_error("Too little information about cylinder\n");
	else
		ft_error("Too much information about cylinder\n");
}
