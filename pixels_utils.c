/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 23:46:48 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/08 15:59:16 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_to_hex(t_color c)
{
	return (((int)c.r << 16) | ((int)c.g << 8) | (int)c.b);
}

int	pixel_color(t_world *w, t_ray *ray, float t)
{
	t_vector	hit_point;
	t_vector	normal;
	t_color		color;

	w->ray_temp = *ray;
	hit_point = ray_position(ray->o, ray->dir, t);
	normal = get_normal(&w->obj_temp, hit_point);
	color = lit(w, hit_point, normal, w->obj_temp.color);
	return (color_to_hex(color));
}
