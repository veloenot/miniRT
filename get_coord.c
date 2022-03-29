/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:42:30 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 16:42:32 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_get_coord_err_str(char **err, char *elem)
{
	char	*tmp;

	*err = ft_strjoin("Unacceptable ", elem);
	if (!(*err))
		ft_error_sys_call();
	tmp = *err;
	*err = ft_strjoin(*err, " coordinates\n");
	free(tmp);
	if (!(*err))
		ft_error_sys_call();
}

void	ft_check_coord(char **coord, char *elem)
{
	char	*err;

	ft_get_coord_err_str(&err, elem);
	while (*coord != NULL)
	{
		ft_str_is_valid_float(*coord, err);
		coord++;
	}
	free(err);
}

static char	*ft_get_coord_err_little(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too little information about ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, " coordinates\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

static char	*ft_get_coord_err_much(char *elem)
{
	char	*err;
	char	*tmp;

	err = ft_strjoin("Too much information about ", elem);
	if (!err)
		ft_error_sys_call();
	tmp = err;
	err = ft_strjoin(err, " coordinates\n");
	free(tmp);
	if (!err)
		ft_error_sys_call();
	return (err);
}

void	ft_get_coord(char *coord_param, t_vector **coord, char *name_elem)
{
	char	**arr_coord;
	int		count;

	arr_coord = ft_split_coord(coord_param);
	count = ft_count_params(arr_coord);
	if (count == 3)
	{
		ft_check_coord(arr_coord, name_elem);
		ft_new_vector(coord);
		ft_set_coord(arr_coord, &((*coord)->x), &((*coord)->y), &((*coord)->z));
		ft_free_arr(arr_coord);
	}
	else if (count < 3)
		ft_error(ft_get_coord_err_little(name_elem));
	else
		ft_error(ft_get_coord_err_much(name_elem));
}
