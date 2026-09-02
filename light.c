/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:58:20 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/02 15:25:29 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//TODO: clamp system
//TODO: color math



t_color	lit(t_world *w, t_vector hit_point, t_vector normal, t_color obj_color)
{
	t_vector		light_dir;
	float			spot_light;
	t_color			result_color;
	float			dist_shadow;
	t_vector		shadow_dir;

	light_dir = vector_sub(w->light->vec3, hit_point);
	light_dir = normalise_vector(&light_dir);
	spot_light = dot_product(normal, light_dir);
	dist_shadow = shadow_dist(w, hit_point);
	shadow_dir = shadow_position(hit_point, normal);
	if (spot_light < 0.f)
		spot_light = 0.f;
	spot_light *= w->light->lighting;
	result_color.r = obj_color.r * (w->ambient->color.r / 255.f) * w->ambient->lighting;
		/* * w->ambient->lighting + obj_color.r * (w->light->color.r / 255.f)
		* spot_light;*/
	result_color.g = obj_color.g * (w->ambient->color.g / 255.f) * w->ambient->lighting;
		/* * w->ambient->lighting + obj_color.g * (w->light->color.g / 255.f)
		* spot_light;*/
	result_color.b = obj_color.b * (w->ambient->color.b / 255.f) * w->ambient->lighting;
		/* * w->ambient->lighting + obj_color.b * (w->light->color.b / 255.f)
		* spot_light;*/

	int i = 0;
	float t_shadow;
	int omb = 0;
	int inter = 0;
	t_ray shadow_ray;
	shadow_ray.dir = light_dir;
	shadow_ray.o = shadow_dir;
	while (w->form[i] != NULL)
	{
		t_shadow = 0;
		/*if(w->form[i] == &w->obj_temp)
		{
			i++;
			continue ;
		}*/
		if (w->form[i]->identifier == SPHERE)
			inter = intersect_sphere(&shadow_ray, w->form[i], &t_shadow);
		else if (w->form[i]->identifier == PLANE)
			inter = intersect_plane(&shadow_ray, w->form[i], &t_shadow);
		else if (w->form[i]->identifier == CYLINDER)
			inter = intersect_cylinder(&shadow_ray, w->form[i], &t_shadow);
		if (inter == 0)
		{
			i++;
			continue ;
		}
		if (t_shadow > 0 && t_shadow < dist_shadow)
		{
			//printf ("test = %f\n", dist_shadow);
			//printf ("t_shadow = %f\n", t_shadow);
			omb = 1;
		}
		i++;
	}
	if (omb == 0)
	{
		result_color.r += obj_color.r * (w->light->color.r / 255.f) * spot_light;
		result_color.g += obj_color.g * (w->light->color.g / 255.f) * spot_light;
		result_color.b += obj_color.b * (w->light->color.b / 255.f) * spot_light;
	}
	if (result_color.r > 255.f)
		result_color.r = 255.f;
	if (result_color.g > 255.f)
		result_color.g = 255.f;
	if (result_color.b > 255.f)
		result_color.b = 255.f;
	/*if (result_color.r < 0.f)
		result_color.r = 0.f;
	if (result_color.g < 0.f)
		result_color.g = 0.f;
	if (result_color.b < 0.f)
		result_color.b = 0.f;*/
	return (result_color);
}

t_vector	shadow_position(t_vector hit_point, t_vector normal)
{
	t_vector	result;

	result = vector_mult(normal, 0.001f);
	result = vector_add(hit_point, result);
	return (result);
}

float shadow_dist(t_world *w, t_vector hit_point)
{
	float		result;
	t_vector	raw;

	raw = vector_sub(w->light->vec3, hit_point);
	result = get_magnitude(&raw);
	return (result);
}



/*
    t_vector hit_point = ray_position(w->camera->vec3, ray->dir, t);
    t_vector dir = vector_sub(w->light->vec3, hit_point);
    dir = normalise_vector(&dir);
    t_vector norm = get_normal(&w->obj_temp, hit_point);
    float dist = get_magnitude(vector_sub(w->light->vec3, hit_point));
    float t_shadow = vector_add(hit_point, vector_mult(norm, FLT_EPSILON));
    if (t_shadow > 0 && t_shadow < dist)
    {

    }
*/