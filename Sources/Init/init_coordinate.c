/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:46:39 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/11 17:11:42 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_coordinate(t_world *w, t_obj *obj, int cat)
{
	char	**coor_temp;
	int		i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	coor_temp = ft_split(w->info[cat], ',');
	if (count_tab(coor_temp) > 3)
	{
		free_double_ptr((void **)coor_temp, count_tab(coor_temp));
		exit_message("Error: too many coordinate arguments\n", w, 2);
	}
	while (coor_temp[i] != NULL)
	{
		if (isinf(ft_atof(coor_temp[i])) || !count_sign(coor_temp[i]))
		{
			free_double_ptr((void **)coor_temp, count_tab(coor_temp));
			exit_message("Error: bad coordinate argument\n", w, 2);
		}
		i++;
	}
	obj->vec3.x = ft_atof(coor_temp[0]);
	obj->vec3.y = ft_atof(coor_temp[1]);
	obj->vec3.z = ft_atof(coor_temp[2]);
	free_double_ptr((void **)coor_temp, count_tab(coor_temp));
}

void	set_color(t_world *w, t_obj *obj, int cat)
{
	char	**color_temp;
	int		i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	color_temp = ft_split(w->info[cat], ',');
	if (count_tab(color_temp) > 3)
	{
		free_double_ptr((void **)color_temp, count_tab(color_temp));
		exit_message("Error: too many color arguments\n", w, 2);
	}
	while (color_temp[i] != NULL)
	{
		if ((ft_atof(color_temp[i]) < 0.f || ft_atof(color_temp[i]) > 255.f)
			|| !count_sign(color_temp[i]))
		{
			free_double_ptr((void **)color_temp, count_tab(color_temp));
			exit_message("Error: bad color arguments\n", w, 2);
		}
		i++;
	}
	obj->color.r = ft_atof(color_temp[0]);
	obj->color.g = ft_atof(color_temp[1]);
	obj->color.b = ft_atof(color_temp[2]);
	free_double_ptr((void **)color_temp, count_tab(color_temp));
}

float	set_size(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("Error: bad argument size\n", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("Error: bad argument size\n", w, 2);
	if (result < 0)
		exit_message("Error: bad argument size\n", w, 2);
	return (result);
}

float	set_ratio_light(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("Error: bad argument size\n", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("Error: bad argument ration\n", w, 2);
	if (result < 0.f || result > 1.f)
		exit_message("Error: bad argument ration\n", w, 2);
	return (result);
}

void	set_normalisation(t_world *w, t_obj *obj, int cat)
{
	char	**norm_temp;
	int		i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	norm_temp = ft_split(w->info[cat], ',');
	if (count_tab(norm_temp) > 3)
	{
		free_double_ptr((void **)norm_temp, count_tab(norm_temp));
		exit_message("Error: too many color arguments\n", w, 2);
	}
	while (norm_temp[i] != NULL)
	{
		if ((ft_atof(norm_temp[i]) < -1.f || ft_atof(norm_temp[i]) > 1.f)
			|| !count_sign(norm_temp[i]))
		{
			free_double_ptr((void **)norm_temp, count_tab(norm_temp));
			exit_message("Error: bad arguments color\n", w, 2);
		}
		i++;
	}
	obj->norm.x = ft_atof(norm_temp[0]);
	obj->norm.y = ft_atof(norm_temp[1]);
	obj->norm.z = ft_atof(norm_temp[2]);
	free_double_ptr((void **)norm_temp, count_tab(norm_temp));
}
