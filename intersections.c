/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:37:13 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/06 17:55:39 by rhmontei         ###   ########.fr       */
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
