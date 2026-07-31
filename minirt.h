/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:16:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/31 16:50:00 by gcamara          ###   ########.fr       */
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

typedef struct s_obj
{
	int			identifier;
	t_vector	vec3;
	t_vector	rot3;
	t_color		color;
	float		diameter;
	float		height;
	float		lighting;
	float		fov;
	char		**info;
}			t_obj;

typedef void (*atributs)(t_obj *obj, t_obj **tab);

//////////////////////////////
/*			INIT			*/
//////////////////////////////

int		count_objs(char **argv);
void	init_objets(t_obj **obj, int count, char **argv);
t_obj	**init_structs(t_obj **obj, int count);
int		ft_strcmp(const char *s1, const char *s2);
int		attribut_identifier(char *identifier);
void	attribute_info(t_obj *obj, t_obj **tab);
int		is_valid(int argc, char **argv);
int		count_tab(char **tab);
void	set_coordinate(t_obj *obj, t_obj **tab);
void    check_value_coordinate(char *str, t_obj **tab);
void	add_ambiant(t_obj *obj, t_obj **tab);
void	add_light(t_obj *obj, t_obj **tab);
void	add_camera(t_obj *obj, t_obj **tab);
void	add_sphere(t_obj *obj, t_obj **tab);
void	add_plane(t_obj *obj, t_obj **tab);
void	add_cylindre(t_obj *obj, t_obj **tab);

//////////////////////////////
/*			MATH			*/
//////////////////////////////

float    ft_atof(const char *nptr);


//////////////////////////////
/*			EXIT			*/
//////////////////////////////

void	free_tab(char **tab);
void	free_objs(t_obj **obj);
void	exit_message(char *message, t_obj **obj, int code);

#endif