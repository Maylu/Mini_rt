/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:54:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/03 19:11:07 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void add_ambiant(int index, t_obj **obj)
{
    (void)obj;
    (void)index;
	return ;
}
void add_light(int index, t_obj **obj)
{
    (void)obj;
    (void)index;
	return ;
}
void add_camera(int index, t_obj **obj)
{
    (void)obj;
    (void)index;
	return ;
}

void add_sphere(int index, t_obj **obj)
{
    set_coordinate(index, obj, 1);
    set_color(index, obj, 3);
    obj[index]->diameter = ft_atof(obj[index]->info[2]);
    obj[index]->identifier = attribut_identifier(obj[index]->info[0]);
}
void add_plane(int index, t_obj **obj)
{
    (void)obj;
    (void)index;
	return ;
}
void add_cylindre(int index, t_obj **obj)
{
    (void)obj;
    (void)index;
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