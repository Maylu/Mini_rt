/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 23:46:48 by rhmontei          #+#    #+#             */
/*   Updated: 2026/08/28 01:15:52 by rhmontei         ###   ########.fr       */
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

    hit_point = ray_position(ray->o, ray->dir, t);
    normal = get_normal(&w->obj_temp, hit_point);
    color = lit(w, hit_point, normal, w->obj_temp.color);
    return (color_to_hex(color));
}

