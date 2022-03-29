/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:38:15 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 19:38:16 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow_sp(t_sphere *sp, t_vector *light, t_vector *surface, float lt_len)
{
	t_sphere	*tmp;
	float		dist;

	tmp = sp;
	while (tmp)
	{
		dist = sp_int(tmp->coord, light, tmp, surface);
		if (dist > 0.05 && dist < lt_len)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
