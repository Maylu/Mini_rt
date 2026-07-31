/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:46:39 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/31 16:48:27 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    check_value_coordinate(char *str, t_obj **tab)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if((!ft_isdigit(str[i])) && str[i] != ',')
			exit_message("bad arguments", tab, 2);
		i++;
	}
}

void set_coordinate(t_obj *obj, t_obj **tab)
{
	char    **coor_temp;
	int     i;

	i = 0;
	check_value_coordinate(obj->info[1], tab);
	coor_temp = ft_split(obj->info[1], ',');
	if (count_tab(coor_temp) > 3)
	{
		free_tab(coor_temp);
		exit_message("too much arguments coor 1", tab, 2);
	}
	while(coor_temp[i] != NULL)
	{
		if (isinf(ft_atof(coor_temp[i])))
		{
			free_tab(coor_temp);
			exit_message("too much arguments coor 2", tab, 2);
		}
		i++;
	}
	obj->vec3.x = ft_atof(coor_temp[0]);
	obj->vec3.y = ft_atof(coor_temp[1]);
	obj->vec3.z = ft_atof(coor_temp[2]);
}