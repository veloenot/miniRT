/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:52:51 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 19:52:52 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	while_cy(t_cylinder *cy, int x, int y, int z)
{
	while (cy)
	{
		cy->coord->x += x;
		cy->coord->y += y;
		cy->coord->z += z;
		cy = cy->next;
	}
}

static void	move_cam(t_scene *scene, int x, int y, int z)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	sp = scene->sp;
	while (sp)
	{
		sp->coord->x += x;
		sp->coord->y += y;
		sp->coord->z += z;
		sp = sp->next;
	}
	pl = scene->pl;
	while (pl)
	{
		pl->coord->x += x;
		pl->coord->y += y;
		pl->coord->z += z;
		pl = pl->next;
	}
	cy = scene->cy;
	while_cy(cy, x, y, z);
}

static void	add_val(t_scene *scene, int x, int y, int z)
{
	if (scene->ms->sep_sp)
	{
		scene->ms->sp->coord->x -= x;
		scene->ms->sp->coord->y -= y;
		scene->ms->sp->coord->z += z;
	}
	if (scene->ms->sep_pl)
	{
		scene->ms->pl->coord->x -= x;
		scene->ms->pl->coord->y -= y;
		scene->ms->pl->coord->z += z;
	}
	if (scene->ms->sep_cy)
	{
		scene->ms->cy->coord->x -= x;
		scene->ms->cy->coord->y -= y;
		scene->ms->cy->coord->z += z;
	}
}

void	ft_move(t_scene *scene, int x, int y, int z)
{
	int	lt_mv;
	int	cam_mv;

	cam_mv = 1 - scene->ms->sep_sp - scene->ms->sep_pl - scene->ms->sep_cy;
	lt_mv = (1 - scene->lt_move * 2) * cam_mv;
	cam_mv -= scene->lt_move;
	if (cam_mv)
		move_cam(scene, x, y, z);
	scene->lt->coord->x += x * lt_mv;
	scene->lt->coord->y += y * lt_mv;
	scene->lt->coord->z += z * (cam_mv + scene->lt_move);
	add_val(scene, x, y, z);
}
