/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:54:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/11 14:13:48 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void add_ambiant(t_world *w)
{
    if (count_tab (w->info) > 3)
        exit_message("bad number of arguments", w, 2);
    set_color(w, w->ambient, A_COLOR);
    w->ambient->identifier = attribut_identifier(w->info[A_ID]);
    w->ambient->lighting = set_ratio_light(w, A_RATIO);
}

void add_light(t_world *w)
{
    (void)w;
    return ;
    /*if (count_tab (w->info) > 4)
        exit_message("bad number of arguments", w, 2);
    set_coordinate(w, L_COOR);
    set_color(w, L_COLOR);
    w->light->lighting = set_ratio_light(w, L_RATIO);
    w->light->identifier = attribut_identifier(w->info[L_ID]);*/
}
void add_camera(t_world *w)
{
    (void)w;
    return ;
   /*if (count_tab (obj[index]->info) > 4)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate (index, obj, C_COOR);
    set_normalisation (index, obj, C_NORM);
    set_fov(index, obj, C_FOV);
    obj[index]->identifier = attribut_identifier(obj[index]->info[C_ID]);*/
}

void add_sphere(t_world *w)
{
    if (count_tab (w->info) > 4)
        exit_message("bad number of arguments", w, 2);
    set_coordinate(w, w->form[w->index], S_COOR);
    set_color(w, w->form[w->index], S_COLOR);
    w->form[w->index]->diameter = set_size(w, S_DIAM);
    w->form[w->index]->identifier = attribut_identifier(w->info[S_ID]);
}

void add_plane(t_world *w)
{
    if (count_tab (w->info) > 4)
        exit_message("bad number of arguments", w, 2);
    set_coordinate(w, w->form[w->index], P_COOR);
    set_normalisation (w, w->form[w->index], P_NORM);
    set_color(w, w->form[w->index], P_COLOR);
    w->form[w->index]->identifier = attribut_identifier(w->info[P_ID]);
}

void add_cylindre(t_world *w)
{
    (void)w;
    return ;
    /*if (count_tab (obj[index]->info) > 6)
        exit_message("bad number of arguments", obj, 2);
    set_coordinate (index, obj, CY_COOR);
    set_color(index, obj, CY_COLOR);
    obj[index]->diameter = set_size(index, obj, CY_DIAM);
    obj[index]->height = set_size(index, obj, CY_HEIGHT);
    set_normalisation (index, obj, CY_NORM);
    obj[index]->identifier = attribut_identifier(obj[index]->info[CY_ID]);*/
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