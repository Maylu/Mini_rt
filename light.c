/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:58:20 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/04 20:03:37 by gcamara          ###   ########.fr       */
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
	float	specular;

	i = 0;
	result_color = color_mix(obj_color, w->ambient->color);
	result_color = color_scale(result_color, w->ambient->lighting);
	while (i < w->nb_lights)
	{
		if (!is_in_shadow(w, w->lights[i], hit_point, normal))
		{
			light_color = get_light_color(w->lights[i], hit_point, normal,
					obj_color);
			specular = get_specular(w->lights[i], hit_point, normal, w->ray_temp);
			light_color	= specular_add(light_color, specular * 255);
			result_color = color_add(result_color, light_color);
		}
		i++;
	}
	result_color.r = clamp_color(result_color.r);
	result_color.g = clamp_color(result_color.g);
	result_color.b = clamp_color(result_color.b);
	return (result_color);
}

float	get_specular(t_obj *light, t_vector hit_point, t_vector normal, t_ray ray)
{
	t_vector		norm;
	t_vector		r;
	t_vector		v;
	t_vector		light_dir;
	float			specular;

	light_dir = get_light_dir(light, hit_point);
	light_dir = normalise_vector(&light_dir);
	norm = normalise_vector(&normal);
	r = vector_sub(vector_mult(norm, 2.f * fmax(0.0f, dot_product(norm, light_dir))), light_dir);
	r = normalise_vector(&r);
	v = vector_mult(ray.dir, -1);
	v = normalise_vector(&v);
	specular = 0.5f * light->lighting * pow(fmax(0.0f, dot_product(r, v)), 64);
	return (specular);
}