/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:10:50 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:10:54 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_new_camera(t_camera **cam)
{
	*cam = (t_camera *)malloc(sizeof(t_camera));
	if (!(*cam))
		ft_error_sys_call();
	(*cam)->coord = NULL;
	(*cam)->dir = NULL;
	(*cam)->fov = 0;
	(*cam)->angle_x = 0;
	(*cam)->angle_y = 0;
}

static void	ft_check_fov_range(float fov)
{
(void)fov;
//	if (fov < 0 || fov > 180)
//		ft_error("Invalid FOV for camera!\nUse in the range [0,180]\n");
}

static void	ft_get_fov(char *fov_param, t_scene *scene)
{
	ft_str_is_valid_float(fov_param, "Invalid FOV\n");
	scene->cam->fov = ft_get_float(fov_param);
	ft_check_fov_range(scene->cam->fov);
}

void	ft_add_camera(char **params, t_scene *scene)
{
	int	count;

	count = ft_count_params(params);
	if (count == 4)
	{
		ft_new_camera(&(scene->cam));
		ft_get_coord(params[1], &(scene->cam->coord), "camera");
		ft_get_norm_vector(params[2], &(scene->cam->dir), "camera");
		ft_get_fov(params[3], scene);
	}
	else if (count < 4)
		ft_error("Too little information about camera\n");
	else
		ft_error("Too much information about camera\n");
}
