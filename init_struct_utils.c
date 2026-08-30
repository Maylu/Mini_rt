/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:37:43 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/27 03:48:44 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char 	*clean_line(char **line)
{
	int len;

	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (*line);
}

void check_doubles(t_world *w, char *tab)
{
	if (attribut_identifier(tab) == CAMERA)
		w->is_camera++;
	if (attribut_identifier(tab) == LIGHT)
		w->is_light++;
	//if (attribut_identifier(tab) == CAMERA)
	if (attribut_identifier(tab) == AMBIENT_LIGHT)
		w->is_ambient++;
}

void	clean_memory(t_world *w, char **line)
{
	free_tab(w->info);
	w->info = NULL;
	free(*line);
	*line = NULL;
}

void print_test(t_world *w)
{
		printf("Sphere:\n");
	printf("  Diameter : %f\n", w->form[1]->diameter);
	printf("  Position : x = %f, y = %f, z = %f\n",
    w->form[1]->vec3.x, w->form[1]->vec3.y, w->form[1]->vec3.z);
	printf("  Color    : r = %f, g = %f, b = %f\n",
    w->form[1]->color.r, w->form[1]->color.g, w->form[1]->color.b);
	printf("Plane:\n");
	printf("  Position : x = %f, y = %f, z = %f\n",
    w->form[0]->vec3.x, w->form[0]->vec3.y, w->form[0]->vec3.z);
	printf("  Norm : x = %f, y = %f, z = %f\n",
    w->form[0]->norm.x, w->form[0]->norm.y, w->form[0]->norm.z);
	printf("  Color    : r = %f, g = %f, b = %f\n",
    w->form[0]->color.r, w->form[0]->color.g, w->form[0]->color.b);


	printf("Ambiant light:\n");
	printf("  Ratio : %f\n", w->ambient->lighting);
	printf("  Color    : r = %f, g = %f, b = %f\n",
    w->ambient->color.r, w->ambient->color.g, w->ambient->color.b);

	/*printf("Light:\n");
	printf("  Position : x = %f, y = %f, z = %f\n",
    obj[2]->vec3.x, obj[2]->vec3.y, obj[2]->vec3.z);
	printf("  Ratio : %f\n", obj[2]->lighting);
	printf("  Color    : r = %f, g = %f, b = %f\n",
    obj[2]->color.r, obj[2]->color.g, obj[2]->color.b);

	printf("Camera:\n");
	printf("  Position : x = %f, y = %f, z = %f\n",
    obj[1]->vec3.x, obj[1]->vec3.y, obj[1]->vec3.z);
	printf("  Norm    : x = %f, y = %f, z = %f\n",
    obj[1]->norm.x, obj[1]->norm.y, obj[1]->norm.z);
	printf("  Fov : %f\n", obj[1]->fov);*/
}