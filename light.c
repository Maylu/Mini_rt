/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:58:20 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/03 22:32:46 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	clamp_color(float color)
{
	if (color > 255.f)
		return (255.f);
	if (color < 0.f)
		return (0.f);
	return (color);
}

t_vector	get_light_dir(t_obj *light, t_vector hit_point)
{
	t_vector	light_dir;

	light_dir = vector_sub(light->vec3, hit_point);
	light_dir = normalise_vector(&light_dir);
	return (light_dir);
}

t_color	get_light_color(t_obj *light, t_vector hit_point,
		t_vector normal, t_color obj_color)
{
	t_vector	light_dir;
	float		light_factor;
	t_color		light_color;

	light_dir = get_light_dir(light, hit_point);
	light_factor = dot_product(normal, light_dir) * light->lighting;
	if (light_factor < 0.f)
		light_factor = 0.f;
	light_color = color_mix(obj_color, light->color);
	light_color = color_scale(light_color, light_factor);
	return (light_color);
}

t_color	lit(t_world *w, t_vector hit_point, t_vector normal, t_color obj_color)
{
	int		i;
	t_color	result_color;
	t_color	light_color;
	//t_vector light_dir;

	i = 0;
	result_color = color_mix(obj_color, w->ambient->color);
	result_color = color_scale(result_color, w->ambient->lighting);
	while (i < w->nb_lights)
	{
		//light_dir = get_light_dir(w->lights[i], hit_point);
		if (!is_in_shadow(w, w->lights[i], hit_point, normal))
		{
			light_color = get_light_color(w->lights[i], hit_point, normal,
					obj_color);
			result_color = color_add(result_color, light_color);
		}
		i++;
	}
	result_color.r = clamp_color(result_color.r);
	result_color.g = clamp_color(result_color.g);
	result_color.b = clamp_color(result_color.b);
	return (result_color);
}

/*
	t_vector hit_point = ray_position(w->camera->vec3, ray->dir, t);
	t_vector dir = vector_sub(w->lights->vec3, hit_point);
	dir = normalise_vector(&dir);
	t_vector norm = get_normal(&w->obj_temp, hit_point);
	float dist = get_magnitude(vector_sub(w->lights->vec3, hit_point));
	float t_shadow = vector_add(hit_point, vector_mult(norm, FLT_EPSILON));
	if (t_shadow > 0 && t_shadow < dist)
	{

	}
*/