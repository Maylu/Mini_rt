/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:46:39 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/14 15:12:49 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int count_sign(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-')
				&& (!(ft_isdigit(str[i + 1]))))
				return (0);
		i++;
	}
	return (1);
}

void    check_value_coordinate(char *str, t_world *w, int flag)
{
	int i;
	int point = 0;

	i = 0;

	printf("%s\n", str);

	if (flag == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '.' && point == 1)
				exit_message("bad arguments2", w, 2);
			if (str[i] == '.')
				point = 1;
			if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != '.' && str[i] != '+' && str[i] != '-')
				exit_message("bad arguments1", w, 2);
			if (str[i] == ',' || str[i + 1] == '\0')
				point = 0;
			i++;
		}
	}
	else if (flag == 0)
	{
		while (str[i] != '\0')
		{
			if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '+' && str[i] != '-')
				exit_message("bad arguments1", w, 2);
			i++;
		}
	}
}
//DONE: check value coor and ajust for 1.2.3 for exemple

//DONE: handle Camera ambient and light object bool
//DONE: handle scene with minimun object C L and A
//DONE: handle 1. to be 1.0
//DONE: continue with others objets
//DONE: + - sign
//DONE: create mlx scene
//TODO: init camera in scene
//DONE: create struct scene

void set_coordinate(t_world *w, t_obj *obj, int cat)
{
	char    **coor_temp;
	int     i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	coor_temp = ft_split(w->info[cat], ',');
	if (count_tab(coor_temp) > 3)
	{
		free_tab(coor_temp);
		exit_message("too much arguments coordinate", w, 2);
	}
	while(coor_temp[i] != NULL)
	{
		if (isinf(ft_atof(coor_temp[i])) || !count_sign(coor_temp[i]))
		{
			free_tab(coor_temp);
			exit_message("bad argument coordinate", w, 2);
		}
		i++;
	}
	obj->vec3.x = ft_atof(coor_temp[0]);
	obj->vec3.y = ft_atof(coor_temp[1]);
	obj->vec3.z = ft_atof(coor_temp[2]);
	free_tab(coor_temp);
}

void    set_color(t_world *w, t_obj *obj, int cat)
{
	char	**color_temp;
	int		i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	color_temp = ft_split(w->info[cat], ',');
	if (count_tab(color_temp) > 3)
    {
        free_tab(color_temp);
        exit_message("too much arguments color", w, 2);
    }
	while(color_temp[i] != NULL)
	{
		if ((ft_atof(color_temp[i]) < 0.f || ft_atof(color_temp[i]) > 255.f) 
			|| !count_sign(color_temp[i]))
		{
			free_tab(color_temp);
			exit_message("bad arguments color", w, 2);
		}
		i++;
	}
    obj->color.r = ft_atof(color_temp[0]);
    obj->color.g = ft_atof(color_temp[1]);
    obj->color.b = ft_atof(color_temp[2]);
	free_tab(color_temp);
}

float set_size(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("bad argument size", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("bad argument size", w, 2);
	if (result < 0)
		exit_message("bad argument size", w, 2);
	return (result);
}

float  set_ratio_light(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("bad argument size", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("bad argument ration", w, 2);
	if (result < 0.f || result > 1.f)
		exit_message("bad argument ration", w, 2);
	return (result);
}

void    set_normalisation(t_world *w, t_obj *obj, int cat)
{
	char **norm_temp;
	int		i;

	i = 0;
	check_value_coordinate(w->info[cat], w, 1);
	norm_temp = ft_split(w->info[cat], ',');
	if (count_tab(norm_temp) > 3)
    {
        free_tab(norm_temp);
        exit_message("too much arguments color", w, 2);
    }
	while(norm_temp[i] != NULL)
	{
		if ((ft_atof(norm_temp[i]) < -1.f || ft_atof(norm_temp[i]) > 1.f) 
			|| !count_sign(norm_temp[i]))
		{
			free_tab(norm_temp);
			exit_message("bad arguments color", w, 2);
		}
		i++;
	}
    obj->norm.x = ft_atof(norm_temp[0]);
    obj->norm.y = ft_atof(norm_temp[1]);
    obj->norm.z = ft_atof(norm_temp[2]);
	free_tab(norm_temp);
}

float  set_fov(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("bad argument size", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("bad argument fov", w, 2);
	if (result < 0.f || result > 180.f)
		exit_message("bad argument fov", w, 2);
	return (result);
}
