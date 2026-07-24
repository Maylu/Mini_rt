/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:16:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/24 18:52:49 by gcamara          ###   ########.fr       */
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
}			t_obj;

#endif