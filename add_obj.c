/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:54:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/31 16:47:39 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void add_ambiant(t_obj *obj, t_obj **tab)
{
    (void)obj;
    (void)tab;
	return ;
}
void add_light(t_obj *obj, t_obj **tab)
{
    (void)obj;
    (void)tab;
	return ;
}
void add_camera(t_obj *obj, t_obj **tab)
{
    (void)obj;
    (void)tab;
	return ;
}

void add_sphere(t_obj *obj, t_obj **tab)
{
    char **color_temp;
    color_temp = ft_split(obj->info[3], ',');
    set_coordinate(obj, tab);
    if (count_tab(color_temp) > 3)
    {
        free_tab(color_temp);
        exit_message("too much arguments", tab, 2);
    }
    obj->color.r = ft_atof(color_temp[0]);
    if (obj->color.r < 0 || obj->vec3.x > 255)
        exit_message("rgb not coform", tab, 2);
    obj->color.g = ft_atof(color_temp[1]);
    if (obj->color.g < 0 || obj->vec3.y > 255)
        exit_message("rgb not coform", tab, 2);
    obj->color.b = ft_atof(color_temp[2]);
    if (obj->color.b < 0 || obj->vec3.z > 255)
        exit_message("rgb not coform", tab, 2);
    obj->diameter = ft_atof(obj->info[2]);
    obj->identifier = attribut_identifier(obj->info[0]);
    free_tab(color_temp);
}
void add_plane(t_obj *obj, t_obj **tab)
{
    (void)obj;
    (void)tab;
	return ;
}
void add_cylindre(t_obj *obj, t_obj **tab)
{
    (void)obj;
    (void)tab;
	return ;
}

float    ft_atof(const char *nptr)
{
    int    i;
    int    negative;
    double    result;
    double   decimal;

    i = 0;
    negative = 0.0;
    result = 0.0;
    decimal = 0.1;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            negative++;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    
    if (nptr[i] == '.')
    {
      i++;
      while (nptr[i] >= '0' && nptr[i] <= '9')
      {
        result = result + (nptr[i] - '0') * decimal;
        decimal = decimal / 10;
        i++;
      }
    }
    if (negative % 2 != 0)
        result *= -1;
    return ((float)result);
}