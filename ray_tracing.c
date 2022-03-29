/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:24:59 by jkassand          #+#    #+#             */
/*   Updated: 2022/02/14 21:36:19 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_sp_in(t_inter *in, t_vector *ray, t_sphere *sp, t_vector *cam)
{
	float		dist;
	t_sphere	*tmp;

	in->sp_dist = 0;
	tmp = sp;
	while (tmp)
	{
		dist = sp_int(tmp->coord, ray, tmp, cam);
		if (dist > 1 && (!in->sp_dist || dist < in->sp_dist))
		{
			in->sp_dist = dist;
			in->sp = tmp;
		}
		tmp = tmp->next;
	}
}

static void	rt_pl_in(t_inter *in, t_vector *ray, t_plane *pl, t_vector *cam)
{
	float		dist;
	t_plane		*tmp;

	in->pl_dist = 0;
	tmp = pl;
	while (tmp)
	{
		dist = ray->x * tmp->dir->x + ray->y * tmp->dir->y + \
			ray->z * tmp->dir->z;
		if (dist)
			dist = ((tmp->coord->x - cam->x) * tmp->dir->x + \
					(tmp->coord->y - cam->y) * tmp->dir->y + \
					(tmp->coord->z - cam->z) * tmp->dir->z) / dist;
		if (dist > 1 && (!in->pl_dist || dist < in->pl_dist))
		{
			in->pl_dist = dist;
			in->pl = tmp;
		}
		tmp = tmp->next;
	}
}

void	rt_cy_in(t_inter *in, t_vector *ray, t_cylinder *cy, t_vector *cam)
{
	float		dist;
	t_cylinder	*tmp;

	in->cy_dist = 0;
	tmp = cy;
	while (tmp)
	{
		dist = cy_int(tmp->coord, ray, tmp, cam);
		if (dist > 1 && (!in->cy_dist || dist < in->cy_dist))
		{
			in->cy_dist = dist;
			in->cy = tmp;
		}
		tmp = tmp->next;
	}
}

static void	rt_init(t_raytrace *rt, t_scene *scene)
{
	float	len_ray;

	rt->color = 0;
	rt->ray.x = (rt->x - WIDTH / 2) * scene->vp->x;
	rt->ray.y = (HEIGHT / 2 - rt->y) * scene->vp->y;
	rt->ray.z = -1;
	len_ray = sqrtf(rt->ray.x * rt->ray.x + rt->ray.y * rt->ray.y + \
			rt->ray.z * rt->ray.z);
	rt->ray.x /= len_ray;
	rt->ray.y /= len_ray;
	rt->ray.z /= len_ray;
	rt_sp_in(scene->in, &rt->ray, scene->sp, scene->cam->coord);
	rt_pl_in(scene->in, &rt->ray, scene->pl, scene->cam->coord);
	rt_cy_in(scene->in, &rt->ray, scene->cy, scene->cam->coord);
	rt->sp = scene->in->sp_dist;
	rt->pl = scene->in->pl_dist;
	rt->cy = scene->in->cy_dist;
}

void	ray_tracing(void *mlx_ptr, void *win_ptr, t_scene *scene)
{
	t_raytrace	rt;
	char		*dst;

	rt.y = -1;
	while (++rt.y < HEIGHT)
	{
		rt.x = -1;
		while (++rt.x < WIDTH)
		{
			rt_init(&rt, scene);
			if (rt.sp && ((rt.pl && rt.sp < rt.pl) || !rt.pl)
				&& ((rt.cy && rt.sp < rt.cy) || !rt.cy))
				rt.color = get_sp_color(scene, &rt.ray, rt.sp);
			else if (rt.pl && ((rt.cy && rt.pl < rt.cy) || !rt.cy))
				rt.color = get_pl_color(scene, &rt.ray, rt.pl);
			else if (rt.cy)
				rt.color = get_cy_color(scene, &rt.ray, rt.cy);
			dst = scene->img->addr + rt.y * scene->img->line_length + \
				rt.x * (scene->img->bits_per_pixel / 8);
			*(unsigned int *)dst = rt.color;
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, scene->img->img, 0, 0);
}
