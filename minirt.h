/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:16:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/30 14:41:45 by gcamara          ###   ########.fr       */
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
# include <X11/keysym.h>
# include "Includes/GNL/get_next_line.h"
# include "Includes/libft/libft.h"

enum e_identifier
{
	AMBIENT_LIGHT = 1,
	LIGHT = 2,
	CAMERA = 3,
	SPHERE = 4,
	PLANE = 5,
	CYLINDER = 6,
};

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}		t_vector;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
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

//////////////////////////////
/*			INIT			*/
//////////////////////////////

int		count_objs(char **argv);
void	init_objets(t_obj **obj, int count, char **argv);
t_obj	**init_structs(t_obj **obj, int count);
int		ft_strcmp(const char *s1, const char *s2);
int		attribut_identifier(char *identifier);
int		is_valid(int argc, char **argv);

//////////////////////////////
/*			EXIT			*/
//////////////////////////////

void	free_tab(char **tab);
void	free_objs(t_obj **obj);
void	exit_message(char *message, t_obj **obj, int code);

#endif