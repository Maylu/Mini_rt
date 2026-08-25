/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:54:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/24 17:50:23 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
    printf("prout");
    if (count_tab (w->info) > 4)
        exit_message("bad number of arguments", w, 2);
    set_coordinate(w, w->form[w->index], P_COOR);
    set_normalisation (w, w->form[w->index], P_NORM);
    w->form[w->index]->norm = normalise_vector(&w->form[w->index]->norm);
    set_color(w, w->form[w->index], P_COLOR);
    w->form[w->index]->identifier = attribut_identifier(w->info[P_ID]);
}

void add_cylindre(t_world *w)
{
    if (count_tab (w->info) > 6)
        exit_message("bad number of arguments", w, 2);
    set_coordinate (w, w->form[w->index], CY_COOR);
    set_color(w, w->form[w->index], CY_COLOR);
    w->form[w->index]->diameter = set_size(w, CY_DIAM);
    w->form[w->index]->height = set_size(w, CY_HEIGHT);
    set_normalisation (w, w->form[w->index], CY_NORM);
    w->form[w->index]->norm = normalise_vector(&w->form[w->index]->norm);
    w->form[w->index]->identifier = attribut_identifier(w->info[CY_ID]);
}
