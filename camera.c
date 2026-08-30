/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:01:18 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/27 19:40:57 by rhmontei         ###   ########.fr       */
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
	float temp;

	temp = 0.f;
	temp = dot_product(w->right_vec, w->up_vec);
	if (temp != 0)
		exit_message("va niquer1", w, 2);
	temp = dot_product(w->camera->norm, w->up_vec);
	if (temp != 0)
		exit_message("va niquer2", w, 2);
	temp = dot_product(w->right_vec, w->camera->norm);
	if (temp != 0)
		exit_message("va niquer3", w, 2);
}

//DONE: apply normalise
//DONE: finish while condition
//DONE: ray condition
//TODO: intersection condition with t
//TODO: color ray condition

t_vector	set_viewport_up_right(t_world *w)
{
	t_vector	world_up;
	t_vector	view_up_right;

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
	view_up_right = vector_add(w->camera->vec3,
			vector_mult(w->camera->norm, V_DIST)); // left?
	view_up_right = vector_add(view_up_right, vector_sub(vector_mult
				(vector_mult(w->u, -1.f), 0.5f), vector_mult(w->v, 0.5f)));
	return (view_up_right);
}

/*right vec = camera->normal *world up (0,1,0) to get the right vector of the camera. Then, calculate the up vector by taking the cross product of the right vector and the camera's normal. Finally, set the viewport's position and orientation based on these vectors and the camera's position.
upvec =  right vec * camera->normal

u viewplaneHeight = 2 * tan(fov/2) * viewplaneDist
v viewplaneWidth  = viewplaneHeight * aspectRatio

viewport_u = rightVec * viewplaneWidth        // horizontal
viewport_v = -upVec   * viewplaneHeight        // vertical, inversé pour descendre

viewPlaneUpLeft = camPos + vecDir*viewplaneDist(1) + upVec*(viewplaneHeight/2) - rightVec*(viewplaneWidth/2)

void set_camera(t_world *w)
{
	t_vector test = vector_add (w->camera->vec3, vector_mult(w->camera->norm, 1));
	t_vector test2 = vector_sub (vector_mult(w->u, w->v_width / 2.f), vector_mult(w->v, w->v_height / 2.f));
	test = vector_add(test, test2);
}
❶Place the camera and the viewport as desired

viewPlaneUpLeft = camPos + ((vecDir*viewplaneDist)+(upVec*(viewplaneHeight/2.0f))) - (rightVec*(viewplaneWidth/2.0f))

vec3 coor cam + ((norm cam * distance))

For each pixel on the canvas
480 x 270
	❷Determine which square on the viewport corresponds to this pixel
	❸Determine the color seen through that square
	❹Paint the pixel with that color*/