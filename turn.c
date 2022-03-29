/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:08:50 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 20:08:53 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	vec_turn(t_vector *ray, int angle_x, int angle_y)
{
	float	x;
	float	y;
	float	z;

	x = ray->x * cosf(-angle_x * M_PI / 180) - \
		ray->z * sinf(-angle_x * M_PI / 180);
	y = -ray->x * sinf(-angle_x * M_PI / 180) * sinf(-angle_y * M_PI / 180) + \
		ray->y * cosf(-angle_y * M_PI / 180) - \
		ray->z * cosf(-angle_x * M_PI / 180) * sinf(-angle_y * M_PI / 180);
	z = ray->x * sinf(-angle_x * M_PI / 180) * cosf(-angle_y * M_PI / 180) + \
		ray->y * sinf(-angle_y * M_PI / 180) + \
		ray->z * cosf(-angle_x * M_PI / 180) * cosf(-angle_y * M_PI / 180);
	ray->x = x;
	ray->y = y;
	ray->z = z;
}

static void	while_pl_cy(t_plane *pl, t_cylinder *cy, int angle_x, int angle_y)
{
	while (pl)
	{
		vec_turn(pl->coord, angle_x, angle_y);
		vec_turn(pl->dir, angle_x, angle_y);
		pl = pl->next;
	}
	while (cy)
	{
		vec_turn(cy->coord, angle_x, angle_y);
		vec_turn(cy->dir, angle_x, angle_y);
		cy = cy->next;
	}
}

void	turn(t_scene *scene, int angle_x, int angle_y)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	sp = scene->sp;
	pl = scene->pl;
	cy = scene->cy;
	if (!scene->ms->sep_sp && !scene->ms->sep_pl && !scene->ms->sep_cy)
	{
		while (sp)
		{
			vec_turn(sp->coord, angle_x, angle_y);
			sp = sp->next;
		}
		while_pl_cy(pl, cy, angle_x, angle_y);
		vec_turn(scene->lt->coord, angle_x, angle_y);
	}
	if (scene->ms->sep_pl)
		vec_turn(scene->ms->pl->dir, -angle_x, -angle_y);
	if (scene->ms->sep_cy)
		vec_turn(scene->ms->cy->dir, angle_x, angle_y);
}
