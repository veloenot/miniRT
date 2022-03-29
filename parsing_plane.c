/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:24 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:26 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_new_plane(t_plane **plane)
{
	*plane = (t_plane *)malloc(sizeof(t_plane));
	if (!(*plane))
		ft_error_sys_call();
	(*plane)->coord = NULL;
	(*plane)->dir = NULL;
	(*plane)->color = NULL;
	(*plane)->next = NULL;
}

static void	ft_add_back_plane(t_plane **plane, t_plane *new)
{
	t_plane	*tmp;

	tmp = *plane;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_add_plane(char **params, t_scene *scene)
{
	int		count;
	t_plane	*plane;
	t_plane	*tmp;

	count = ft_count_params(params);
	if (count == 4)
	{
		ft_new_plane(&plane);
		if (!scene->pl)
			scene->pl = plane;
		else
			ft_add_back_plane(&(scene->pl), plane);
		tmp = scene->pl;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_get_coord(params[1], &(tmp->coord), "plane");
		ft_get_norm_vector(params[2], &(tmp->dir), "plane");
		ft_get_color(params[3], &(tmp->color), "plane");
	}
	else if (count < 4)
		ft_error("Too little information about plane\n");
	else
		ft_error("Too much information about plane\n");
}
