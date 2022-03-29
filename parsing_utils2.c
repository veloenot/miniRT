/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:08 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 17:29:10 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_scene(t_scene scene)
{
	if (scene.la == NULL || scene.cam == NULL || scene.lt == NULL)
		ft_error("Too little information about the scene\n");
}

void	ft_set_coord(char **coord, float *x, float *y, float *z)
{
	*x = ft_get_float(coord[0]);
	*y = ft_get_float(coord[1]);
	*z = ft_get_float(coord[2]);
}
