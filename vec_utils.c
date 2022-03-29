/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:14:44 by jkassand          #+#    #+#             */
/*   Updated: 2021/10/26 23:41:56 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_malloc(int size)
{
	void	*res;

	res = malloc(size);
	if (!res)
	{
		perror("Memory error");
		exit(1);
	}
	return (res);
}

t_vector	*new_vector(float x, float y, float z)
{
	t_vector	*vec;

	vec = ft_malloc(sizeof(t_vector));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

void	vec_normalize(t_vector	*vec)
{
	float	len;

	len = sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

void	vec_subtract(t_vector *res, t_vector *vec_1, t_vector *vec_2)
{
	res->x = vec_1->x - vec_2->x;
	res->y = vec_1->y - vec_2->y;
	res->z = vec_1->z - vec_2->z;
}

void	get_cam_angle(t_camera *cam)
{
	t_vector	*xz;
	t_vector	*yz;

	xz = new_vector(cam->dir->x, 0, cam->dir->z);
	vec_normalize(xz);
	yz = new_vector(0, cam->dir->y, cam->dir->z);
	vec_normalize(yz);
	cam->angle_x = acosf(-xz->z) * 180 / M_PI;
	if (xz->x < 0)
		cam->angle_x = -cam->angle_x;
	cam->angle_y = acosf(-yz->z) * 180 / M_PI;
	if (yz->y < 0)
		cam->angle_y = -cam->angle_y;
	free(xz);
	free(yz);
}
