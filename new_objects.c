/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:10:01 by jkassand          #+#    #+#             */
/*   Updated: 2021/10/26 23:38:55 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(t_vector *coord, t_vector *color, float r)
{
	t_sphere	*sp;

	sp = ft_malloc(sizeof(t_sphere));
	sp->coord = coord;
	sp->color = color;
	sp->r = r;
	return (sp);
}

t_plane	*new_plane(t_vector *coord, t_vector *dir, t_vector *color)
{
	t_plane	*pl;

	pl = ft_malloc(sizeof(t_plane));
	pl->coord = coord;
	pl->dir = dir;
	pl->color = color;
	return (pl);
}

t_camera	*new_camera(t_vector *coord, t_vector *dir, float fov)
{
	t_camera	*cam;

	cam = ft_malloc(sizeof(t_camera));
	cam->coord = coord;
	cam->dir = dir;
	cam->fov = fov;
	return (cam);
}

t_light	*new_light(t_vector *coord, t_vector *color, float ratio)
{
	t_light	*lt;

	lt = ft_malloc(sizeof(t_light));
	lt->coord = coord;
	lt->color = color;
	lt->ratio = ratio;
	return (lt);
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		ratio;

	vplane = ft_malloc(sizeof(t_vplane));
	ratio = width / height;
	vplane->width = tanf(fov / 2 * M_PI / 180) * 2;
	vplane->height = vplane->width / ratio;
	vplane->x = vplane->width / width;
	vplane->y = vplane->height / height;
	return (vplane);
}
