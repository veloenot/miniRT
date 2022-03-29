/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:02:13 by jkassand          #+#    #+#             */
/*   Updated: 2021/10/26 23:06:04 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	deal_key_2(int key, t_scene *scene)
{
	if (key == 37)
		scene->lt_move = set_one(scene);
	if (key == 12)
		set_one(scene);
	if (key == 24 && scene->ms->sep_sp)
		scene->ms->sp->r++;
	if (key == 27 && scene->ms->sep_sp)
		scene->ms->sp->r--;
	if (key == 24 && scene->ms->sep_cy)
	{
		scene->ms->cy->r++;
		scene->ms->cy->h *= scene->ms->cy->r / (scene->ms->cy->r - 1);
	}
	if (key == 27 && scene->ms->sep_cy && scene->ms->cy->r > 1)
	{
		scene->ms->cy->r--;
		scene->ms->cy->h *= scene->ms->cy->r / (scene->ms->cy->r + 1);
	}
	if (key != 12 && key != 37)
		ray_tracing(scene->mlx, scene->win, scene);
}

int	set_one(t_scene *scene)
{
	scene->lt_move = 0;
	scene->ms->sep_sp = 0;
	scene->ms->sep_pl = 0;
	scene->ms->sep_cy = 0;
	return (1);
}

int	deal_key(int key, t_scene *scene)
{
	(void)scene;
	if (key == 53)
		exit(0);
	if (key == 126)
		ft_move(scene, 0, -10, 0);
	if (key == 125)
		ft_move(scene, 0, 10, 0);
	if (key == 124)
		ft_move(scene, -10, 0, 0);
	if (key == 123)
		ft_move(scene, 10, 0, 0);
	if (key == 0)
		turn(scene, -1, 0);
	if (key == 2)
		turn(scene, 1, 0);
	if (key == 1)
		turn(scene, 0, -1);
	if (key == 13)
		turn(scene, 0, 1);
	deal_key_2(key, scene);
	return (0);
}

static void	set_obj(t_scene *scene)
{
	float	max;

	max = scene->ms->sp_dist;
	if (scene->ms->cy_dist > max)
		max = scene->ms->cy_dist;
	if (scene->ms->pl_dist > max)
		max = scene->ms->pl_dist;
	if (!scene->ms->sp_dist)
		scene->ms->sp_dist = max + 1;
	if (!scene->ms->pl_dist)
		scene->ms->pl_dist = max + 1;
	if (!scene->ms->cy_dist)
		scene->ms->cy_dist = max + 1;
	if (scene->ms->pl_dist < scene->ms->sp_dist && \
		scene->ms->pl_dist < scene->ms->cy_dist)
		scene->ms->sep_pl = set_one(scene);
	else if (scene->ms->cy_dist < scene->ms->sp_dist)
		scene->ms->sep_cy = set_one(scene);
	else
		scene->ms->sep_sp = set_one(scene);
}

int	deal_mouse(int mouse, int x, int y, t_scene *scene)
{
	t_vector	*ray;

	if (mouse == 5)
		ft_move(scene, 0, 0, 10);
	if (mouse == 4)
		ft_move(scene, 0, 0, -10);
	if (mouse == 1)
	{
		ray = new_vector((x - WIDTH / 2) * scene->vp->x, \
				(HEIGHT / 2 - y) * scene->vp->x, -1);
		vec_normalize(ray);
		sps_int(scene->ms, ray, scene->sp, scene->cam->coord);
		planes_int(scene->ms, ray, scene->pl, scene->cam->coord);
		rt_cy_in(scene->ms, ray, scene->cy, scene->cam->coord);
		if (!scene->ms->sp_dist && !scene->ms->pl_dist && !scene->ms->cy_dist)
			set_one(scene);
		else
			set_obj(scene);
		free(ray);
	}
	if (mouse == 2)
		set_one(scene);
	if (mouse != 1 && mouse != 2)
		ray_tracing(scene->mlx, scene->win, scene);
	return (0);
}
