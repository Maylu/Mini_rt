/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:01:18 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/08 18:14:56 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	define_vector(float x, float y, float z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void	check_perpendicular(t_world *w)
{
	float	temp;

	temp = 0.f;
	temp = dot_product(w->right_vec, w->up_vec);
	if (temp != 0)
		exit_message("Error : angle perpendicular", w, 2);
	temp = dot_product(w->camera->norm, w->up_vec);
	if (temp != 0)
		exit_message("Error : angle perpendicular", w, 2);
	temp = dot_product(w->right_vec, w->camera->norm);
	if (temp != 0)
		exit_message("Error : angle perpendicular", w, 2);
}

t_vector	set_viewport_up_right(t_world *w)
{
	t_vector	world_up;
	t_vector	view_up_left;

	world_up = define_vector(0.f, 1.f, 0.f);
	w->right_vec = cross_product(w->camera->norm, world_up);
	w->right_vec = normalise_vector(&w->right_vec);
	w->up_vec = cross_product(w->right_vec, w->camera->norm);
	w->up_vec = normalise_vector(&w->up_vec);
	check_perpendicular(w);
	w->mlx.ratio = 16.f / 9.f;
	w->mlx.w = WIDTH;
	w->mlx.h = (int)w->mlx.w / w->mlx.ratio;
	if (w->mlx.h < 1)
		w->mlx.h = 1;
	w->v_height = 2.0 * tan((w->camera->fov * M_PI / 180) / 2) * V_DIST;
	w->v_width = w->v_height * w->mlx.ratio;
	w->u = vector_mult (w->right_vec, w->v_width);
	w->v = vector_mult (vector_mult(w->up_vec, -1.f), w->v_height);
	view_up_left = vector_add(w->camera->vec3,
			vector_mult(w->camera->norm, V_DIST));
	view_up_left = vector_add(view_up_left, vector_sub(vector_mult
				(vector_mult(w->u, -1.f), 0.5f), vector_mult(w->v, 0.5f)));
	return (view_up_left);
}
