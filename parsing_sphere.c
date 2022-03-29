/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:39 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:40 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_new_sphere(t_sphere **sphere)
{
	*sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!(*sphere))
		ft_error_sys_call();
	(*sphere)->coord = NULL;
	(*sphere)->r = 0;
	(*sphere)->color = NULL;
	(*sphere)->next = NULL;
}

static void	ft_add_back_sphere(t_sphere **sphere, t_sphere *new)
{
	t_sphere	*tmp;

	tmp = *sphere;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static void	ft_get_sphere_radius(char *diameter, t_sphere **sphere)
{
	ft_str_is_valid_float(diameter, "Unacceptable sphere diameter\n");
	(*sphere)->r = ft_get_float(diameter) * 0.5;
	if ((*sphere)->r < 0)
		ft_error("Invalid sphere diameter!\nUse d > 0\n");
}

void	ft_add_sphere(char **params, t_scene *scene)
{
	int			count;
	t_sphere	*sphere;
	t_sphere	*tmp;

	count = ft_count_params(params);
	if (count == 4)
	{
		ft_new_sphere(&sphere);
		if (!scene->sp)
			scene->sp = sphere;
		else
			ft_add_back_sphere(&(scene->sp), sphere);
		tmp = scene->sp;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_get_coord(params[1], &(tmp->coord), "sphere");
		ft_get_sphere_radius(params[2], &tmp);
		ft_get_color(params[3], &(tmp->color), "sphere");
	}
	else if (count < 4)
		ft_error("Too little information about sphere\n");
	else
		ft_error("Too much information about sphere\n");
}
