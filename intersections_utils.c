/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:19:23 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/12 13:21:26 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	solve_quadratic(t_quadratic *quad)
{
	float	delta;

	if (fabsf(quad->a) < 0.000001f)
		return (0);
	delta = quad->b * quad->b - 4.0f * quad->a * quad->c;
	if (delta < 0)
		return (0);
	quad->t1 = (-quad->b - sqrtf(delta)) / (2.0f * quad->a);
	quad->t2 = (-quad->b + sqrtf(delta)) / (2.0f * quad->a);
	return (1);
}
int	is_inside_cylinder(t_ray ray, t_obj cylinder, float t)
{
	t_vector	point;
	t_vector	center_to_point;
	float		height_pos;

	if (t <= 0.000001f)
		return (0);
	point = ray_position(ray.o, ray.dir, t);
	center_to_point = vector_sub(point, cylinder.vec3);
	height_pos = dot_product(center_to_point, cylinder.norm);
	if (height_pos < -cylinder.height / 2.0f || height_pos > cylinder.height
		/ 2.0f)
		return (0);
	return (1);
}

int	get_closest_cylinder_t(t_ray ray, t_obj cylinder, t_quadratic quad,
		float *t)
{
	if (is_inside_cylinder(ray, cylinder, quad.t1))
	{
		*t = quad.t1;
		return (1);
	}
	if (is_inside_cylinder(ray, cylinder, quad.t2))
	{
		*t = quad.t2;
		return (1);
	}
	return (0);
}

int	check_cylinder_cap(t_ray ray, t_obj cylinder, int side, float *t)
{
	t_vector point;
	t_vector center_to_point;
	t_obj cap;
	float radius;
    float cap_t;

	radius = cylinder.diameter / 2.0f;
	cap = cylinder;
	cap.vec3 = vector_add(cylinder.vec3, vector_mult(cylinder.norm,
				cylinder.height / 2.0f * side));
	if (!intersect_plane(ray, cap, &cap_t))
		return (0);
	point = ray_position(ray.o, ray.dir, cap_t);
	center_to_point = vector_sub(point, cap.vec3);
	if (dot_product(center_to_point, center_to_point) > radius * radius)
		return (0);
    if (cap_t < *t)
		*t = cap_t;
	return (1);
}