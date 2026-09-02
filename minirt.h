/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:16:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/31 15:34:55 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "Includes/GNL/get_next_line.h"
# include "Includes/libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define A_ID 0
# define A_RATIO 1
# define A_COLOR 2

# define C_ID 0
# define C_COOR 1
# define C_NORM 2
# define C_FOV 3

# define L_ID 0
# define L_COOR 1
# define L_RATIO 2
# define L_COLOR 3

# define S_ID 0
# define S_COOR 1
# define S_DIAM 2
# define S_COLOR 3

# define P_ID 0
# define P_COOR 1
# define P_NORM 2
# define P_COLOR 3

# define CY_ID 0
# define CY_COOR 1
# define CY_NORM 2
# define CY_DIAM 3
# define CY_HEIGHT 4
# define CY_COLOR 5

# define WIDTH 800
# define V_DIST 1
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
# define _USE_MATH_DEFINES

enum			e_identifier
{
	AMBIENT_LIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
};

typedef struct s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	float		ratio;
	void		*mlx;
	void		*mlx_win;
}				t_data;

typedef struct s_obj
{
	int			identifier;
	t_vector	vec3;
	t_vector	norm;
	t_color		color;
	float		diameter;
	float		height;
	float		lighting;
	float		fov;
	int			hit_zone;
}				t_obj;

typedef struct s_quadratic
{
	float		a;
	float		b;
	float		c;
	float		t1;
	float		t2;
}				t_quadratic;

typedef struct s_world
{
	t_obj		**form;
	t_obj		*light;
	t_obj		*ambient;
	t_obj		*camera;
	t_data		mlx;
	int			count_form;
	int			is_light;
	int			is_ambient;
	int			is_camera;
	int			index;
	char		**info;
	float		ratio;
	float		v_width;
	float		v_height;
	t_vector	u;
	t_vector	v;
	float		pixel_u;
	float		pixel_v;
	t_vector	right_vec;
	t_vector	up_vec;
	t_obj		obj_temp;
	int			hit;
}				t_world;

typedef struct s_ray
{
	t_vector	pixel_space;
	t_vector	o;
	t_vector	dir;
}				t_ray;

typedef void	(*t_atributs)(t_world *w);

//////////////////////////////
/*			INIT			*/
//////////////////////////////

void			clean_memory(t_world *w, char **line);
char			*clean_line(char **line);
int				count_objs(char **argv, t_world *w);
void			init_objets(t_world *w, char **argv);
void			init_structs(t_world *w, int count);
int				ft_strcmp(const char *s1, const char *s2);
int				attribut_identifier(char *identifier);
void			attribute_info(int type, t_world *w);
int				is_valid(int argc, char **argv);
int				count_tab(char **tab);
void			check_doubles(t_world *w, char *tab);
void			set_color(t_world *w, t_obj *obj, int cat);
void			set_coordinate(t_world *w, t_obj *obj, int cat);
float			set_size(t_world *w, int cat);
void			check_value_coordinate(char *str, t_world *w, int flag);
int				count_sign(char *str);
void			check_characters(t_world *w, char *c, int flag);
void			check_point(t_world *w, char *c, int *point);
float			set_ratio_light(t_world *w, int cat);
void			set_normalisation(t_world *w, t_obj *obj, int cat);
void			is_hitting(t_world *w, t_ray *ray, float *t);
float			set_fov(t_world *w, int cat);
void			add_ambiant(t_world *w);
void			add_light(t_world *w);
void			add_camera(t_world *w);
void			add_sphere(t_world *w);
void			add_plane(t_world *w);
void			add_cylindre(t_world *w);
t_color			lit(t_world *w, t_vector hit_point, t_vector normal,
					t_color obj_color);
int				color(t_obj *obj);
int				color_to_hex(t_color c);
int				pixel_color(t_world *w, t_ray *ray, float t);
int				ft_strspn(const char s, const char *chars);
void			ft_free_split_charset(int nb, char **dest);
int				count_dest_charset(char const *s, char *c);
int				count_len_charset(char const *s, char *c);
char			**split_lines_charset(char **dest, char const *s, char *c);
char			**ft_split_charset(char const *s, char *c);
t_vector	shadow_position(t_vector hit_point, t_vector normal);
float shadow_dist(t_world *w, t_vector hit_point);


//////////////////////////////
/*			MATH			*/
//////////////////////////////

float			ft_atof(const char *nptr);
float			get_magnitude(t_vector *vec3);
t_vector		normalise_vector(t_vector *vec);
t_vector		cross_product(t_vector a, t_vector b);
t_vector		vector_add(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, t_vector b);
t_vector		vector_mult(t_vector v, float s);
t_vector		ray_position(t_vector origin, t_vector direction, float t);
float			dot_product(t_vector a, t_vector b);
t_vector		cross_product(t_vector a, t_vector b);
t_vector		set_viewport_up_right(t_world *w);
int				intersect_sphere(t_ray *ray, t_obj *sphere, float *t);
int				intersect_plane(t_ray *ray, t_obj *plane, float *t);
int				intersect_cylinder(t_ray *ray, t_obj *cylinder, float *t);
int				solve_quadratic(t_quadratic *quad);
int				is_inside_cylinder(t_ray *ray, t_obj *cylinder, float t);
int				get_closest_cylinder_t(t_ray *ray, t_obj *cylinder,
					t_quadratic *quad, float *t);
int				check_cylinder_cap(t_ray *ray, t_obj *cylinder, int side,
					float *t);
t_vector		get_normal(t_obj *obj, t_vector hit_point);
void			check_perpendicular(t_world *w);

//////////////////////////////
/*			MLX			*/
//////////////////////////////

void			init_mlx(t_world *w);
int				close_window(t_world *w);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			put_pixel(t_world *w, t_vector *view_up_right, t_ray *ray);
int				move_window(int keycode, t_world *w);

//////////////////////////////
/*			EXIT			*/
//////////////////////////////

void			free_tab(char **tab);
void			free_objs(t_obj **obj);
void			exit_message(char *message, t_world *w, int code);

#endif