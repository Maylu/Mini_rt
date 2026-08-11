/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:37:13 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/07 18:25:18 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_sphere(t_vector origin, t_vector direction, t_obj sphere, float *t)
{
	t_vector	origin_to_center;
	float		a;
	float		b;
	float		c;
	float		delta;
    float       radius;

    radius = sphere.diameter / 2;
	origin_to_center = vector_sub(origin, sphere.vec3);
	a = dot_product(direction, direction);
	b = 2.0f * dot_product(direction, origin_to_center);
	c = dot_product(origin_to_center, origin_to_center) - radius * radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	*t = (-b - sqrtf(delta)) / (2 * a);
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

int intersect_plane(t_vector origin, t_vector direction, t_obj plane, float *t)
{
    float   denominator;
    t_vector point_to_origin;

    denominator = dot_product(direction, plane.norm);
    if (fabsf(denominator) < 0.000001f)
        return (0);
    point_to_origin = vector_sub(plane.vec3, origin);
    *t = dot_product(point_to_origin, plane.norm) / denominator;
    if (*t < 0)
        return (0);
    return (1);
}
