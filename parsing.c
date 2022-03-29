/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:10:28 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:10:30 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_open_file(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		ft_error_sys_call();
}

static void	ft_close_file(int fd)
{
	if (close(fd) != 0)
		ft_error_sys_call();
}

static void	ft_check_format(char *scene_name)
{
	char	*format;

	format = ".rt";
	while (*scene_name != '.' && *scene_name != '\0')
		scene_name++;
	if (*scene_name == '\0')
		ft_error("Incorrect file name format\n");
	if (*scene_name == '.')
	{
		if (ft_strncmp(scene_name, format, 4) != 0)
			ft_error("Incorrect file name format\n");
	}
}

static void	ft_init_scene(t_scene *scene)
{
	scene->cam = NULL;
	scene->lt = NULL;
	scene->la = NULL;
	scene->sp = NULL;
	scene->pl = NULL;
	scene->cy = NULL;
}

void	getscene(char *file, t_scene *scene)
{
	int	fd;

	ft_check_format(file);
	ft_open_file(file, &fd);
	ft_init_scene(scene);
	ft_read_file(scene, fd);
	ft_check_scene(*scene);
	ft_close_file(fd);
}
