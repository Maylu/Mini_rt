/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:37:13 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/17 17:36:43 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_sphere(t_ray *ray, t_obj *sphere, float *t)
{
	t_vector	origin_to_center;
	t_quadratic	quad;
	float		radius;

	ft_memset(&quad, 0, sizeof(quad));
	radius = sphere->diameter / 2;
	origin_to_center = vector_sub(ray->o, sphere->vec3);
	quad.a = dot_product(ray->dir, ray->dir);
	quad.b = 2.0f * dot_product(ray->dir, origin_to_center);
	quad.c = dot_product(origin_to_center, origin_to_center) - radius * radius;
	if (!solve_quadratic(&quad))
		return (0);
	if (quad.t1 > 0.000001f)
		*t = quad.t1;
	else if (quad.t2 > 0.000001f)
		*t = quad.t2;
	else
		return (0);
	return (1);
}

int	intersect_plane(t_ray ray, t_obj plane, float *t)
{
	t_vector	point_to_origin;
	float		denominator;

	denominator = dot_product(ray.dir, plane.norm);
	if (fabsf(denominator) < 0.000001f)
		return (0);
	point_to_origin = vector_sub(plane.vec3, ray.o);
	*t = dot_product(point_to_origin, plane.norm) / denominator;
	if (*t < 0)
		return (0);
	return (1);
}

int	intersect_cylinder(t_ray ray, t_obj cylinder, float *t)
{
	t_vector	origin_to_center;
	t_vector	x;
	t_vector	y;
	t_quadratic	quad;
	float		radius;

	radius = cylinder.diameter / 2.0f;
	origin_to_center = vector_sub(ray.o, cylinder.vec3);
	x = vector_sub(origin_to_center, vector_mult(cylinder.norm,
				dot_product(origin_to_center, cylinder.norm)));
	y = vector_sub(ray.dir, vector_mult(cylinder.norm, dot_product(ray.dir,
					cylinder.norm)));
	quad.a = dot_product(y, y);
	quad.b = 2.0f * dot_product(x, y);
	quad.c = dot_product(x, x) - radius * radius;
	*t = FLT_MAX;
	if (solve_quadratic(&quad))
		get_closest_cylinder_t(ray, cylinder, quad, t);
	check_cylinder_cap(ray, cylinder, 1, t);
	check_cylinder_cap(ray, cylinder, -1, t);
	if (*t == FLT_MAX)
		return (0);
	return (1);
}
