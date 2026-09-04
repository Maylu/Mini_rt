/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 23:46:48 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/04 18:11:57 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int color(t_obj *obj)
{
	return (256 * 256 * obj->color.r + 256 * obj->color.g + obj->color.b);
}

int	color_to_hex(t_color c)
{
	return (((int)c.r << 16) | ((int)c.g << 8) | (int)c.b);
}

int pixel_color(t_world *w, t_ray *ray, float t)
{
    t_vector hit_point;
    t_vector normal;
    t_color color;

    w->ray_temp = *ray;
    hit_point = ray_position(ray->o, ray->dir, t);
    normal = get_normal(&w->obj_temp, hit_point);
    color = lit(w, hit_point, normal, w->obj_temp.color);
    return (color_to_hex(color));
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