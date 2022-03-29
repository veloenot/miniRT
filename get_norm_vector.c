/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_norm_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:08:43 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:08:45 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*ft_get_dir_err_little(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too little information about the direction of the ",
			elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, "\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

static char	*ft_get_dir_err_much(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too much information about the direction of the ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, "\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

static void	ft_check_vect_range(float x, float y, float z)
{
	if (x < -1 || x > 1)
		ft_error("Invalid 'x' for vector direction!\nUse in the range [-1,1]\n");
	else if (y < -1 || y > 1)
		ft_error("Invalid 'y' for vector direction!\nUse in the range [-1,1]\n");
	else if (z < -1 || z > 1)
		ft_error("Invalid 'z' for vector direction!\nUse in the range [-1,1]\n");
}

static void	ft_check_zero_vect(float x, float y, float z)
{
	if (x == 0 && y == 0 && z == 0)
		ft_error("The direction vector cannot be zero\n");
}

void	ft_get_norm_vector(char *vect_param, t_vector **dir, char *name_elem)
{
	char	**vect_coord;
	char	count;

	vect_coord = ft_split_coord(vect_param);
	count = ft_count_params(vect_coord);
	if (count == 3)
	{
		ft_check_coord(vect_coord, name_elem);
		ft_new_vector(dir);
		ft_set_coord(vect_coord, &((*dir)->x), &((*dir)->y), &((*dir)->z));
		ft_free_arr(vect_coord);
		ft_check_vect_range((*dir)->x, (*dir)->y, (*dir)->z);
		ft_check_zero_vect((*dir)->x, (*dir)->y, (*dir)->z);
	}
	else if (count < 3)
		ft_error(ft_get_dir_err_little(name_elem));
	else
		ft_error(ft_get_dir_err_much(name_elem));
}
