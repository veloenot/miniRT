/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:25:35 by jkassand          #+#    #+#             */
/*   Updated: 2022/02/14 21:32:58 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_camera
{
	t_vector	*coord;
	t_vector	*dir;
	float		fov;
	int			angle_x;
	int			angle_y;
}	t_camera;

typedef struct s_light
{
	t_vector	*coord;
	t_vector	*color;
	float		ratio;
}	t_light;

typedef struct s_sphere
{
	t_vector		*coord;
	t_vector		*color;
	float			r;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vector		*coord;
	t_vector		*dir;
	t_vector		*color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vector			*coord;
	t_vector			*dir;
	t_vector			*color;
	float				r;
	float				h;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x;
	float	y;
}	t_vplane;

typedef struct s_inter
{
	int			sep_sp;
	float		sp_dist;
	t_sphere	*sp;
	int			sep_pl;
	float		pl_dist;
	t_plane		*pl;
	int			sep_cy;
	float		cy_dist;
	t_cylinder	*cy;
}	t_inter;

typedef struct s_scene
{
	t_camera	*cam;
	t_light		*lt;
	t_light		*la;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_vplane	*vp;
	t_inter		*in;
	t_inter		*ms;
	int			lt_move;
}	t_scene;

typedef struct s_getcol
{
	t_vector	res_c;
	t_vector	surface;
	t_vector	nl;
	t_vector	lt;
	float		cos;
	float		lt_len;
	t_vector	c;
	t_vector	lt_c;
	float		lt_rat;
}	t_getcol;

typedef struct s_raytrace
{
	int			x;
	int			y;
	t_vector	ray;
	int			color;
	float		sp;
	float		pl;
	float		cy;
}	t_raytrace;

typedef struct s_cycoeff
{
	float	a;
	float	b;
	float	c;
}	t_cycoeff;

void		*ft_malloc(int size);
t_vector	*new_vector(float x, float y, float z);
void		vec_normalize(t_vector	*vec);
void		vec_subtract(t_vector *res, t_vector *vec_1, t_vector *vec_2);
void		get_cam_angle(t_camera *cam);

t_sphere	*new_sphere(t_vector *coord, t_vector *color, float r);
t_plane		*new_plane(t_vector *coord, t_vector *dir, t_vector *color);
t_camera	*new_camera(t_vector *coord, t_vector *dir, float fov);
t_light		*new_light(t_vector *coord, t_vector *color, float ratio);
t_vplane	*get_view_plane(float width, float height, float fov);

float		sp_int(t_vector *sp_c, t_vector *ray, t_sphere *sp, t_vector *cam);
void		sps_int(t_inter *in, t_vector *ray, t_sphere *sp, t_vector *cam);
int			shadow_sp(t_sphere *sp, t_vector *lt, t_vector *surf, float lt_len);
void		planes_int(t_inter *in, t_vector *ray, t_plane *pl, t_vector *cam);

int			get_sp_color(t_scene *scene, t_vector *ray, float dist);

int			get_pl_color(t_scene *scene, t_vector *ray, float dist);

void		ray_tracing(void *mlx_ptr, void *win_ptr, t_scene *scene);

void		ft_move(t_scene *scene, int x, int y, int z);
void		turn(t_scene *scene, int angle_x, int angle_y);

int			set_one(t_scene *scene);
int			deal_key(int key, t_scene *scene);
int			deal_mouse(int mouse, int x, int y, t_scene *scene);

/* parsing */
void		getscene(char *file, t_scene *scene);

/* parsing_read_file */
void		ft_read_file(t_scene *scene, int fd);

/* gnl */
char		*ft_ccalloc(size_t count, size_t size);
int			ft_strlcpy_gnl(char *dst, char *src);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_read_gnl(int fd, char **buf, size_t *count, char **tmp);
int			ft_errors_gnl(int fd, char **line, char **tmp, char **buf);
int			ft_result(size_t *count, char **tmp, char **line, char **buf);
int			get_next_line(int fd, char **line);

/* parsing_utils */
int			ft_count_params(char **params);
float		ft_get_float(char *str);
void		ft_new_vector(t_vector **vector);
char		**ft_split_coord(char *param);

/* parsing_utils2 */
void		ft_check_scene(t_scene scene);
void		ft_set_coord(char **coord, float *x, float *y, float *z);

/* check_valid_value */
void		ft_str_is_valid_float(char *str, char *err_message);
void		ft_str_is_valid_int(char *str, char *err_message);
void		ft_check_ratio_range(float ratio, char *elem);

/* check_color_value */
void		ft_check_color(char **colors);
void		ft_check_color_value(int red, int green, int blue, char *elem);

/* errors */
void		ft_error(char *err);
void		ft_error_sys_call(void);

/* free */
void		ft_free_arr(char **arr);

/* ambient light */
void		ft_add_ambient(char **params, t_scene *scene);

/* parsing_camera */
void		ft_add_camera(char **params, t_scene *scene);

/* parsing_light */
void		ft_add_light(char **params, t_scene *scene);

/* parsing_sphere */
void		ft_add_sphere(char **params, t_scene *scene);

/* parsing_plane */
void		ft_add_plane(char **params, t_scene *scene);

/* parsing_cylinder*/
void		ft_add_cylinder(char **params, t_scene *scene);

/* get_color */
void		ft_get_color(char *color_params, t_vector **color, char *name_elem);

/* get_norm_vect */
void		ft_get_norm_vector(char *vect_param,
				t_vector **dir, char *name_elem);

/* get_coord */
void		ft_check_coord(char **coord, char *elem);
void		ft_get_coord(char *coord_param, t_vector **coord, char *name_elem);

void		ft_new_light(t_light **lt);

/* get_cy_color */
int			get_cy_color(t_scene *scene, t_vector *ray, float dist);

/* sp_pl_cy_shad_int */
float		cy_int(t_vector *cy_c, t_vector *ray,
				t_cylinder *cy, t_vector *cam);
/* ray_tracing */
void		rt_cy_in(t_inter *in, t_vector *ray, t_cylinder *cy, t_vector *cam);

/* cy_sh_sp_pl */
int			sp_pl_sh_cy(t_cylinder *cy, t_vector *lt,
				t_vector *surf, float lt_len);
int			cy_sh_sp(t_sphere *sp, t_vector *lt, t_vector *surf, float lt_len);
int			cy_sh_pl(t_plane *pl, t_vector *lt,
				t_vector *surface, float lt_len);

#endif
