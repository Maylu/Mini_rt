/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:46:39 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/03 21:14:33 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    check_value_coordinate(char *str, t_obj **tab)
{
	int i;
	int flag = 0;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			flag = 1;
			printf ("oki");
		}
		printf("char = %c\n", str[i]);
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != '.')
			exit_message("bad arguments1", tab, 2);
		if (str[i] == '.' && flag == 1)
			exit_message("bad arguments2", tab, 2);
		if (str[i] == ',' || str[i + 1] == '\0')
			flag = 0;
		i++;
	}
}
//DONE: check value coor and ajust for 1.2.3 for exemple

//TODO: handle Camera ambient and light object bool
//TODO: handle scene with minimun object C L and A
//DONE: handle 1. to be 1.0
//TODO: continue with others objets

void set_coordinate(int index, t_obj **obj, int cat)
{
	char    **coor_temp;
	int     i;

	i = 0;
	check_value_coordinate(obj[index]->info[cat], obj);
	coor_temp = ft_split(obj[index]->info[cat], ',');
	if (count_tab(coor_temp) > 3)
	{
		free_tab(coor_temp);
		exit_message("too much arguments coordinate", obj, 2);
	}
	while(coor_temp[i] != NULL)
	{
		if (isinf(ft_atof(coor_temp[i])))
		{
			free_tab(coor_temp);
			exit_message("bad argument coordinate", obj, 2);
		}
		i++;
	}
	obj[index]->vec3.x = ft_atof(coor_temp[0]);
	obj[index]->vec3.y = ft_atof(coor_temp[1]);
	obj[index]->vec3.z = ft_atof(coor_temp[2]);
	free_tab(coor_temp);
}

void    set_color(int index, t_obj **obj, int cat)
{
	char	**color_temp;
	int		i;

	i = 0;
	check_value_coordinate(obj[index]->info[cat], obj);
	color_temp = ft_split(obj[index]->info[cat], ',');
	if (count_tab(color_temp) > 3)
    {
        free_tab(color_temp);
        exit_message("too much arguments color", obj, 2);
    }
	while(color_temp[i] != NULL)
	{
		if (ft_atof(color_temp[i]) < 0.f || ft_atof(color_temp[i]) > 255.f)
		{ 
			free_tab(color_temp);
			exit_message("bad arguments color", obj, 2);
		}
		i++;
	}
    obj[index]->color.r = ft_atof(color_temp[0]);
    obj[index]->color.g = ft_atof(color_temp[1]);
    obj[index]->color.b = ft_atof(color_temp[2]);
	free_tab(color_temp);
}

void set_size(int index, t_obj **obj)
{
	char    **size_temp;
	int     i;

	i = 0;
	check_value_coordinate(obj[index]->info[1], obj);
	size_temp = ft_split(obj[index]->info[1], ',');
	if (count_tab(size_temp) > 2)
	{
		free_tab(size_temp);
		exit_message("too much arguments coordinate", obj, 2);
	}
	while(size_temp[i] != NULL)
	{
		if (isinf(ft_atof(size_temp[i])))
		{
			free_tab(size_temp);
			exit_message("bad argument coordinate", obj, 2);
		}
		i++;
	}
	obj[index]->vec3.x = ft_atof(size_temp[0]);
	obj[index]->vec3.y = ft_atof(size_temp[1]);
	obj[index]->vec3.z = ft_atof(size_temp[2]);
	free_tab(size_temp);
}