/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 22:20:55 by rhmontei          #+#    #+#             */
/*   Updated: 2026/09/03 00:28:32 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r + b.r;
	result.g = a.g + b.g;
	result.b = a.b + b.b;
	return (result);
}

t_color	color_scale(t_color color, float factor)
{
	t_color	result;

	result.r = color.r * factor;
	result.g = color.g * factor;
	result.b = color.b * factor;
	return (result);
}

t_color	color_mix(t_color a, t_color b)
{
	t_color result;
	result.r = a.r * (b.r / 255.f);
	result.g = a.g * (b.g / 255.f);
	result.b = a.b * (b.b / 255.f);
	return (result);
}