/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:37:13 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/12 01:03:01 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_sphere(t_ray ray, t_obj sphere, float *t)
{
	t_vector	origin_to_center;
	t_quadratic	quad;
	float		radius;

	radius = sphere.diameter / 2;
	origin_to_center = vector_sub(ray.o, sphere.vec3);
	quad.a = dot_product(ray.dir, ray.dir);
	quad.b = 2.0f * dot_product(ray.dir, origin_to_center);
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

/*int	intersect_sphere(t_obj *sphere, t_ray *r)
{
	float			delta;
    float       	radius;
	t_vector		origin_to_center;
	t_vector		i;

    radius = sphere->diameter / 2;
	origin_to_center = vector_sub(r->o, sphere->vec3);
	i.x = dot_product(r->dir, r->dir);
	i.y = -2.0f * dot_product(r->dir, origin_to_center);
	i.z = dot_product(origin_to_center, origin_to_center) - radius * radius;
	delta = i.y * i.y - 4 * i.x * i.z;
	if (delta < 0)
		return (0);
	if (delta == 0)
		return (1);
	return (2);
}*/

/*void world_intersect (t_obj **sphere, t_ray *r)
{
	//if (intersect_sphere(sphere, r))

}*/

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
	t_vector 	origin_to_center;
	t_vector 	x;
	t_vector 	y;
	t_quadratic quad;
	float 		radius;

	radius = cylinder.diameter / 2.0f;
	origin_to_center = vector_sub(ray.o, cylinder.vec3);
	x = vector_sub(origin_to_center, vector_mult(cylinder.norm,
				dot_product(origin_to_center, cylinder.norm)));
	y = vector_sub(ray.dir, vector_mult(cylinder.norm, dot_product(ray.dir,
					cylinder.norm)));
	quad.a = dot_product(y, y);
	quad.b = 2.0f * dot_product(x, y);
	quad.c = dot_product(x, x) - radius * radius;
	if (!solve_quadratic(&quad))
		return (0);
	return (get_closest_cylinder_t);
}

