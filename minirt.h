/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:16:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/06 18:48:34 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <mlx.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <X11/keysym.h>
# include "Includes/GNL/get_next_line.h"
# include "Includes/libft/libft.h"

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

enum e_identifier
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
	float	x;
	float	y;
	float	z;
}		t_vector;

typedef struct s_color
{
	float		r;
	float		g;
	float		b;
}		t_color;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
	void	*mlx;
	void	*mlx_win;
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
	char		**info;
}			t_obj;



typedef void (*atributs)(int index, t_obj **obj);

//////////////////////////////
/*			INIT			*/
//////////////////////////////

int		count_objs(char **argv);
void	init_objets(t_obj **obj, int count, char **argv);
t_obj	**init_structs(t_obj **obj, int count);
int		ft_strcmp(const char *s1, const char *s2);
int		attribut_identifier(char *identifier);
void	attribute_info(int index, t_obj **obj);
int		is_valid(int argc, char **argv);
int		count_tab(char **tab);
void	set_coordinate(int index, t_obj **obj, int cat);
void    set_color(int index, t_obj **obj, int cat);
float	set_size(int index, t_obj **obj, int cat);
void    check_value_coordinate(char *str, t_obj **tab, int flag);
float	set_ratio_light(int index, t_obj **obj, int cat);
void    set_normalisation(int index, t_obj **obj, int cat);
float	set_fov(int index, t_obj **obj, int cat);
void	add_ambiant(int index, t_obj **obj);
void	add_light(int index, t_obj **obj);
void	add_camera(int index, t_obj **obj);
void	add_sphere(int index, t_obj **obj);
void	add_plane(int index, t_obj **obj);
void	add_cylindre(int index, t_obj **obj);

//////////////////////////////
/*			MATH			*/
//////////////////////////////

float		ft_atof(const char *nptr);
float		get_magnitude(t_vector vec3);
t_vector 	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector    vector_mult(t_vector v, float s);
t_vector    ray_position(t_vector origin, t_vector direction, float t);
float		dot_product(t_vector a, t_vector b);
int			intersect_sphere(t_vector origin, t_vector direction, t_obj sphere, float *t);
int			intersect_plane(t_vector origin, t_vector direction, t_obj plane, float *t);

//////////////////////////////
/*			MLX			*/
//////////////////////////////

void	init_mlx(void);
int		close_window(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		move_window(int keycode, t_data *img);

//////////////////////////////
/*			EXIT			*/
//////////////////////////////

void	free_tab(char **tab);
void	free_objs(t_obj **obj);
void	exit_message(char *message, t_obj **obj, int code);

#endif