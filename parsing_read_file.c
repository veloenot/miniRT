/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:32 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:11:34 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_set_scene_elem(char **params, t_scene *scene)
{
	if (ft_strncmp(*params, "A", 2) == 0)
		ft_add_ambient(params, scene);
	else if (ft_strncmp(*params, "C", 2) == 0)
		ft_add_camera(params, scene);
	else if (ft_strncmp(*params, "L", 2) == 0)
		ft_add_light(params, scene);
	else if (ft_strncmp(*params, "sp", 3) == 0)
		ft_add_sphere(params, scene);
	else if (ft_strncmp(*params, "pl", 3) == 0)
		ft_add_plane(params, scene);
	else if (ft_strncmp(*params, "cy", 3) == 0)
		ft_add_cylinder(params, scene);
	else
		ft_error("Invalid scene element\n");
}

static void	ft_check_double_identifier(t_scene scene, char identifier)
{
	if (identifier == 'A')
	{
		if (scene.la != NULL)
			ft_error("Too many elements of ambient lightning\n");
	}
	else if (identifier == 'C')
	{
		if (scene.cam != NULL)
			ft_error("Too many camera elements\n");
	}
	else if (identifier == 'L')
	{
		if (scene.lt != NULL)
			ft_error("Too many light elements\n");
	}
}

static int	ft_check_identifier(char **element_info, t_scene scene)
{
	if (!(*element_info))
		return (1);
	if (**element_info == 'A')
		ft_check_double_identifier(scene, 'A');
	else if (**element_info == 'C')
		ft_check_double_identifier(scene, 'C');
	else if (**element_info == 'L')
		ft_check_double_identifier(scene, 'L');
	return (0);
}

void	ft_read_file(t_scene *scene, int fd)
{
	int		num;
	char	*line;
	char	**params;

	num = 1;
	while (num > 0)
	{
		num = get_next_line(fd, &line);
		if (num < 0)
			ft_error_sys_call();
		params = ft_split(line, ' ');
		if (!params)
			ft_error_sys_call();
		if (ft_check_identifier(params, *scene) != 0)
		{
			free(line);
			ft_free_arr(params);
			continue ;
		}
		ft_set_scene_elem(params, scene);
		free(line);
		ft_free_arr(params);
	}
}
