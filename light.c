/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:58:20 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/28 01:31:28 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lit(t_world *w, t_vector hit_point, t_vector normal, t_color obj_color)
{
	t_vector	light_dir;
	float		spot_light;
	t_color		result_color;

	light_dir = vector_sub(w->light->vec3, hit_point);
	light_dir = normalise_vector(&light_dir);
	spot_light = dot_product(normal, light_dir);
	if (spot_light < 0.f)
		spot_light = 0.f;
	spot_light *= w->light->lighting;
	result_color.r = obj_color.r * (w->ambient->color.r / 255.f)
		* w->ambient->lighting + obj_color.r * (w->light->color.r / 255.f)
		* spot_light;
	result_color.g = obj_color.g * (w->ambient->color.g / 255.f)
		* w->ambient->lighting + obj_color.g * (w->light->color.g / 255.f)
		* spot_light;
	result_color.b = obj_color.b * (w->ambient->color.b / 255.f)
		* w->ambient->lighting + obj_color.b * (w->light->color.b / 255.f)
		* spot_light;
	if (result_color.r > 255.f)
		result_color.r = 255.f;
	if (result_color.g > 255.f)
		result_color.g = 255.f;
	if (result_color.b > 255.f)
		result_color.b = 255.f;
	return (result_color);
}


