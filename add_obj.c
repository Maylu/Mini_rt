/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:54:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/06 12:22:19 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void add_ambiant(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 3)
        exit_message("bad number of arguments", obj, 2);
    set_color(index, obj, A_COLOR);
    obj[index]->identifier = attribut_identifier(obj[index]->info[A_ID]);
    obj[index]->lighting = set_ratio_light(index, obj, A_RATIO);
}

void add_light(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 4)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate(index, obj, L_COOR);
    set_color(index, obj, L_COLOR);
    obj[index]->lighting = set_ratio_light(index, obj, L_RATIO);
    obj[index]->identifier = attribut_identifier(obj[index]->info[L_ID]);
}
void add_camera(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 4)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate (index, obj, C_COOR);
    set_normalisation (index, obj, C_NORM);
    set_fov(index, obj, C_FOV);
    obj[index]->identifier = attribut_identifier(obj[index]->info[C_ID]);
}

void add_sphere(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 4)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate(index, obj, S_COOR);
    set_color(index, obj, S_COLOR);
    obj[index]->diameter = set_size(index, obj, S_DIAM);
    obj[index]->identifier = attribut_identifier(obj[index]->info[S_ID]);
}

void add_plane(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 4)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate(index, obj, P_COOR);
    set_normalisation (index, obj, P_NORM);
    set_color(index, obj, P_COLOR);
    obj[index]->identifier = attribut_identifier(obj[index]->info[P_ID]);
}

void add_cylindre(int index, t_obj **obj)
{
    if (count_tab (obj[index]->info) > 6)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate (index, obj, CY_COOR);
    set_color(index, obj, CY_COLOR);
    obj[index]->diameter = set_size(index, obj, CY_DIAM);
    obj[index]->height = set_size(index, obj, CY_HEIGHT);
    set_normalisation (index, obj, CY_NORM);
    obj[index]->identifier = attribut_identifier(obj[index]->info[CY_ID]);
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