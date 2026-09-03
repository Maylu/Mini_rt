/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 01:05:24 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/03 01:25:50 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	shadow_position(t_vector hit_point, t_vector normal)
{
	t_vector	result;

	result = vector_mult(normal, 0.001f);
	result = vector_add(hit_point, result);
	return (result);
}

static float	shadow_dist(t_world *w, t_vector hit_point)
{
	float		result;
	t_vector	raw;

	raw = vector_sub(w->lights->vec3, hit_point);
	result = get_magnitude(&raw);
	return (result);
}
int	is_in_shadow(t_world *w, t_vector hit_point, t_vector normal,
		t_vector light_dir)
{
	int		i;
	int		omb;
	float	t_shadow;
	float	dist_shadow;
	t_ray	shadow_ray;

	i = 0;
	omb = 0;
	dist_shadow = shadow_dist(w, hit_point);
	shadow_ray.dir = light_dir;
	shadow_ray.o = shadow_position(hit_point, normal);
	while (w->form[i] != NULL)
	{
		t_shadow = 0;
		if (intersect_obj(&shadow_ray, w->form[i], &t_shadow) == 0)
		{
			i++;
			continue ;
		}
		if (t_shadow > 0.f && t_shadow < dist_shadow)
			omb = 1;
		i++;
	}
	return (omb);
}
