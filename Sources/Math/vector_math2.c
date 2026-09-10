/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:23:25 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/28 01:28:28 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	get_magnitude(t_vector *vec3)
{
	float	x;
	float	y;
	float	z;
	float	result;

	x = pow(vec3->x, 2);
	y = pow(vec3->y, 2);
	z = pow(vec3->z, 2);
	result = sqrt(x + y + z);
	return (result);
}

t_vector	normalise_vector(t_vector *vec)
{
	float		magnitude;
	t_vector	result;

	magnitude = get_magnitude(vec);
	result.x = vec->x / magnitude;
	result.y = vec->y / magnitude;
	result.z = vec->z / magnitude;
	return (result);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_vector	get_normal(t_obj *obj, t_vector hit_point)
{
	t_vector	normal;
	t_vector	ctr_point;

	if (obj->identifier == SPHERE)
	{
		normal = vector_sub(hit_point, obj->vec3);
		normal = normalise_vector(&normal);
	}
	else if (obj->identifier == CYLINDER)
	{
		if (obj->hit_zone == 0)
		{
			ctr_point = vector_sub(hit_point, obj->vec3);
			ctr_point = vector_sub(ctr_point, vector_mult(obj->norm,
						dot_product(ctr_point, obj->norm)));
			normal = normalise_vector(&ctr_point);
		}
		else if (obj->hit_zone == 1)
			normal = obj->norm;
		else
			normal = vector_mult(obj->norm, -1.f);
	}
	else
		normal = obj->norm;
	return (normal);
}
