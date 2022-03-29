/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sp_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:24:31 by jkassand          #+#    #+#             */
/*   Updated: 2021/10/26 21:24:35 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	sp_sh_pl(t_plane *pl, t_vector *lt, t_vector *surface, float lt_len)
{
	t_plane	*tmp;
	float	dist;

	tmp = pl;
	while (tmp)
	{
		dist = lt->x * tmp->dir->x + lt->y * tmp->dir->y + lt->z * tmp->dir->z;
		if (dist)
			dist = ((tmp->coord->x - surface->x) * tmp->dir->x + \
					(tmp->coord->y - surface->y) * tmp->dir->y + \
					(tmp->coord->z - surface->z) * tmp->dir->z) / dist;
		if (dist > 0.01 && dist < lt_len)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	sp_get_color(t_vector *color)
{
	int	res;
	int	red;
	int	green;
	int	blue;

	red = (int)roundf(color->x);
	if (red > 255)
		red = 255;
	if (red < 0)
		red = 0;
	green = (int)roundf(color->y);
	if (green > 255)
		green = 255;
	if (green < 0)
		green = 0;
	blue = (int)roundf(color->z);
	if (blue > 255)
		blue = 255;
	if (blue < 0)
		blue = 0;
	res = (red << 16) | (green << 8) | blue;
	return (res);
}

static void	sp_gc_init(t_getcol *gc, t_scene *scene, t_vector *ray, float dist)
{
	gc->c.x = scene->in->sp->color->x;
	gc->c.y = scene->in->sp->color->y;
	gc->c.z = scene->in->sp->color->z;
	gc->surface.x = ray->x * dist;
	gc->surface.y = ray->y * dist;
	gc->surface.z = ray->z * dist;
	gc->nl.x = gc->surface.x - scene->in->sp->coord->x;
	gc->nl.y = gc->surface.y - scene->in->sp->coord->y;
	gc->nl.z = gc->surface.z - scene->in->sp->coord->z;
	gc->lt_len = sqrtf(gc->nl.x * gc->nl.x + gc->nl.y * gc->nl.y + \
				gc->nl.z * gc->nl.z);
	gc->nl.x /= gc->lt_len;
	gc->nl.y /= gc->lt_len;
	gc->nl.z /= gc->lt_len;
	gc->lt.x = (scene->lt->coord->x - gc->surface.x);
	gc->lt.y = (scene->lt->coord->y - gc->surface.y);
	gc->lt.z = (scene->lt->coord->z - gc->surface.z);
	gc->lt_len = sqrtf(gc->lt.x * gc->lt.x + gc->lt.y * gc->lt.y + \
			gc->lt.z * gc->lt.z);
	gc->lt.x /= gc->lt_len;
	gc->lt.y /= gc->lt_len;
	gc->lt.z /= gc->lt_len;
	gc->res_c.x = gc->c.x * scene->la->color->x * scene->la->ratio / 255;
	gc->res_c.y = gc->c.y * scene->la->color->y * scene->la->ratio / 255;
	gc->res_c.z = gc->c.z * scene->la->color->z * scene->la->ratio / 255;
}

static void	sp_gc_init_2(t_getcol *gc, t_scene *scene)
{
	gc->lt_c.x = scene->lt->color->x;
	gc->lt_c.y = scene->lt->color->y;
	gc->lt_c.z = scene->lt->color->z;
	gc->lt_rat = scene->lt->ratio;
	gc->cos = 0;
}

int	get_sp_color(t_scene *scene, t_vector *ray, float dist)
{
	t_getcol	gc;

	sp_gc_init(&gc, scene, ray, dist);
	sp_gc_init_2(&gc, scene);
	if (shadow_sp(scene->sp, &gc.lt, &gc.surface, gc.lt_len) || \
		sp_sh_pl(scene->pl, &gc.lt, &gc.surface, gc.lt_len) || \
		sp_pl_sh_cy(scene->cy, &gc.lt, &gc.surface, gc.lt_len))
		return (sp_get_color(&gc.res_c));
	gc.cos = gc.nl.x * gc.lt.x + gc.nl.y * gc.lt.y + gc.nl.z * gc.lt.z;
	if (gc.cos > 0)
	{
		gc.res_c.x += gc.c.x * gc.lt_c.x * gc.lt_rat * gc.cos / 255;
		gc.res_c.y += gc.c.y * gc.lt_c.y * gc.lt_rat * gc.cos / 255;
		gc.res_c.z += gc.c.z * gc.lt_c.z * gc.lt_rat * gc.cos / 255;
	}
	gc.cos = (gc.lt.x - 2 * gc.cos * gc.nl.x) * ray->x + \
			(gc.lt.y - 2 * gc.cos * gc.nl.y) * ray->y + \
			(gc.lt.z - 2 * gc.cos * gc.nl.z) * ray->z;
	if (gc.cos > 0)
	{
		gc.res_c.x += gc.c.x * gc.lt_c.x * gc.lt_rat * powf(gc.cos, 50) / 255;
		gc.res_c.y += gc.c.y * gc.lt_c.y * gc.lt_rat * powf(gc.cos, 50) / 255;
		gc.res_c.z += gc.c.z * gc.lt_c.z * gc.lt_rat * powf(gc.cos, 50) / 255;
	}
	return (sp_get_color(&gc.res_c));
}
