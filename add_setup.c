/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:44:28 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/24 17:50:23 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_ambiant(t_world *w)
{
	if (count_tab (w->info) > 3) 
		exit_message("bad number of arguments", w, 2);
	set_color(w, w->ambient, A_COLOR);
	w->ambient->identifier = attribut_identifier(w->info[A_ID]);
	w->ambient->lighting = set_ratio_light(w, A_RATIO);
}

void	add_light(t_world *w)
{
	if (count_tab (w->info) > 4)
		exit_message("bad number of arguments", w, 2);
	set_coordinate(w, w->light, L_COOR);
	set_color(w, w->light, L_COLOR);
	w->light->lighting = set_ratio_light(w, L_RATIO);
	w->light->identifier = attribut_identifier(w->info[L_ID]);
}

void	add_camera(t_world *w)
{
	if (count_tab (w->info) > 4)
		exit_message("bad number of arguments", w, 2);
	set_coordinate (w, w->camera, C_COOR);
	set_normalisation (w, w->camera, C_NORM);
    w->camera->norm = normalise_vector(&w->camera->norm);
	w->camera->fov = set_fov(w, C_FOV);
	w->camera->identifier = attribut_identifier(w->info[C_ID]);
}