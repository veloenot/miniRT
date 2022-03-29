/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:42:00 by tmillenn          #+#    #+#             */
/*   Updated: 2022/01/09 17:42:02 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_inter	*new_inter(void)
{
	t_inter	*in;

	in = ft_malloc(sizeof(t_inter));
	in->sep_sp = 0;
	in->sp_dist = 0;
	in->sp = NULL;
	in->sep_pl = 0;
	in->pl_dist = 0;
	in->pl = NULL;
	in->sep_cy = 0;
	in->cy_dist = 0;
	in->cy = NULL;
	return (in);
}

static int	ft_exit(int key)
{
	(void)key;
	exit(1);
}

static void	set_hook(t_scene *scene)
{
	mlx_mouse_hook(scene->win, deal_mouse, scene);
	mlx_hook(scene->win, 2, 1L << 0, deal_key, scene);
	mlx_hook(scene->win, 17, 1L << 0, ft_exit, scene);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		exit(1);
	scene.img = ft_malloc(sizeof(t_img));
	scene.in = new_inter();
	scene.ms = new_inter();
	set_one(&scene);
	getscene(argv[1], &scene);
	scene.vp = get_view_plane(WIDTH, HEIGHT, scene.cam->fov);
	get_cam_angle(scene.cam);
	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, WIDTH, HEIGHT, argv[1]);
	scene.img->img = mlx_new_image(scene.mlx, WIDTH, HEIGHT);
	scene.img->addr = mlx_get_data_addr(scene.img->img, \
		&scene.img->bits_per_pixel, &scene.img->line_length,
			&scene.img->endian);
	ft_move(&scene, -scene.cam->coord->x, -scene.cam->coord->y,
		-scene.cam->coord->z);
	turn(&scene, scene.cam->angle_x, scene.cam->angle_y);
	vec_subtract(scene.cam->coord, scene.cam->coord, scene.cam->coord);
	ray_tracing(scene.mlx, scene.win, &scene);
	set_hook(&scene);
	mlx_loop(scene.mlx);
	exit(0);
}
