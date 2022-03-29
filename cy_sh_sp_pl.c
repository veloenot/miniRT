/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_sh_sp_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:28:48 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 17:28:50 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cy_sh_sp(t_sphere *sp, t_vector *lt, t_vector *surf, float lt_len)
{
	t_sphere	*tmp;
	float		dist;

	tmp = sp;
	while (tmp)
	{
		dist = sp_int(tmp->coord, lt, tmp, surf);
		if (dist > 0.01 && dist < lt_len)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	cy_sh_pl(t_plane *pl, t_vector *lt, t_vector *surface, float lt_len)
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

int	sp_pl_sh_cy(t_cylinder *cy, t_vector *lt, t_vector *surf, float lt_len)
{
	t_cylinder	*tmp;
	float		dist;

	tmp = cy;
	while (tmp)
	{
		dist = cy_int(tmp->coord, lt, tmp, surf);
		if (dist > 0.01 && dist < lt_len)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
