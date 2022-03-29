/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_pl_cy_shad_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:35:25 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 17:35:27 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sp_int(t_vector *sp_c, t_vector *ray, t_sphere *sp, t_vector *cam)
{
	float		b;
	float		c;
	float		discr;
	float		dist;
	t_vector	csp;

	csp.x = sp_c->x - cam->x;
	csp.y = sp_c->y - cam->y;
	csp.z = sp_c->z - cam->z;
	b = -2 * (csp.x * ray->x + csp.y * ray->y + csp.z * ray->z);
	c = csp.x * csp.x + csp.y * csp.y + csp.z * csp.z - sp->r * sp->r;
	discr = b * b - 4 * c;
	if (discr < 0)
		return (0);
	dist = (-b - sqrtf(discr)) / 2;
	if (dist <= 0)
		dist = (-b + sqrtf(discr)) / 2;
	return (dist);
}

void	sps_int(t_inter *in, t_vector *ray, t_sphere *sp, t_vector *cam)
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

void	planes_int(t_inter *in, t_vector *ray, t_plane *pl, t_vector *cam)
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

void	get_coefficient(t_vector *ray, t_cylinder *cy,
						t_vector ccy, t_cycoeff *coeff)
{
	coeff->a = 1 - pow(ray->x * cy->dir->x + ray->y * \
						cy->dir->y + ray->z * cy->dir->z, 2);
	coeff->b = -2 * ((ray->x * ccy.x + ray->y * ccy.y + ray->z * ccy.z) - \
			(ray->x * cy->dir->x + ray->y * cy->dir->y + ray->z * cy->dir->z) * \
			(ccy.x * cy->dir->x + ccy.y * cy->dir->y + ccy.z * cy->dir->z));
	coeff->c = (ccy.x * ccy.x + ccy.y * ccy.y + ccy.z * ccy.z) - \
		pow(ccy.x * cy->dir->x + ccy.y * cy->dir->y + ccy.z * cy->dir->z, 2) - \
		cy->r * cy->r;
}

float	cy_int(t_vector *cy_c, t_vector *ray, t_cylinder *cy, t_vector *cam)
{
	float		m;
	float		discr;
	float		dist;
	t_cycoeff	coeff;
	t_vector	ccy;

	ccy.x = cy_c->x - cam->x;
	ccy.y = cy_c->y - cam->y;
	ccy.z = cy_c->z - cam->z;
	vec_normalize(cy->dir);
	get_coefficient(ray, cy, ccy, &coeff);
	discr = coeff.b * coeff.b - 4 * coeff.a * coeff.c;
	if (discr < 0)
		return (0);
	dist = (-coeff.b - sqrtf(discr)) / (2 * coeff.a);
	m = (ray->x * cy->dir->x + ray->y * cy->dir->y + ray->z * cy->dir->z) * \
		dist - (ccy.x * cy->dir->x + ccy.y * cy->dir->y + ccy.z * cy->dir->z);
	if (dist > 0 && m >= 0 && m <= cy->h)
		return (dist);
	dist = (-coeff.b + sqrtf(discr)) / (2 * coeff.a);
	m = (ray->x * cy->dir->x + ray->y * cy->dir->y + ray->z * cy->dir->z) * \
		dist - (ccy.x * cy->dir->x + ccy.y * cy->dir->y + ccy.z * cy->dir->z);
	if (dist > 0 && m >= 0 && m <= cy->h)
		return (dist);
	return (0);
}
