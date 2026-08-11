/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:36:59 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/11 14:56:36 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_objs(char **argv, t_world *w)
{
	int		file;
	int		count;
	char	*line;
	char	**tab;

	count = 0;
	file = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		tab = ft_split(line, '\t');
		if (attribut_identifier(tab[0]) >= 0)
			count++;
		check_doubles(w, tab[0]);
		free_tab(tab);
		free (line);
		line = NULL;
	}
	close (file);
	if (w->is_camera != 1 || w->is_light != 1 || w->is_ambient != 1)
		exit(0);
	return (count);
}

void	init_structs(t_world *w, int count)
{
	int	i;

	i = 0;
	w->count_form = count - 3;
	w->form = malloc(sizeof(t_obj *) *(w->count_form + 1));
	if (w->form == NULL)
		exit(1);
	while (i < (w->count_form))
	{
		w->form[i] = malloc(sizeof(t_obj));
		if (w->form[i] == NULL)
			exit(1);
		ft_memset(w->form[i], 0, sizeof(t_obj));
		i++;
	}
	w->form[i] = NULL;
	w->camera = malloc(sizeof(t_obj));
	if (w->form == NULL)
		exit(1);
	w->ambient = malloc(sizeof(t_obj));
	if (w->form == NULL)
		exit(1);
	w->light = malloc(sizeof(t_obj));
	if (w->form == NULL)
		exit(1);
}

char 	*clean_line(char **line)
{
	int len;

	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return(*line);
}

void check_doubles(t_world *w, char *tab)
{
	if (attribut_identifier(tab) == CAMERA)
		w->is_camera++;
	if (attribut_identifier(tab) == LIGHT)
		w->is_light++;
	if (attribut_identifier(tab) == CAMERA)
		w->is_ambient++;
}

void	init_objets(t_world *w, int count, char **argv)
{
	int		file;
	char	*line;

	(void)count;
	file = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		line = clean_line(&line);
		w->info = ft_split(line, '\t');
		if (w->info[0] == NULL || attribut_identifier(w->info[0]) < 0 )
		{
			free_tab(w->info);
			w->info = NULL;
			free(line);
			line = NULL;
			continue;
		}
		free (line);
		line = NULL;
		attribute_info(attribut_identifier(w->info[0]), w);
		if(attribut_identifier(w->info[0]) > 2)
			w->index++;
		free_tab(w->info);
		w->info = NULL;
	}
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
	close (file);
}

void	attribute_info(int type, t_world *w)
{
	t_atributs	f[6];

	f[0] = &add_ambiant;
	f[1] = &add_light;
	f[2] = &add_camera;
	f[3] = &add_sphere;
	f[4] = &add_plane;
	f[5] = &add_cylindre;

	f[type](w);
	/*while (i < 6)
	{
		if (i == attribut_identifier(w->form[index]->info[0]))
			f[i](index, obj);
		i++;
	}
	if (attribut_identifier(info[0]) == CAMERA)
		f[2](index, obj);
	else if (attribut_identifier(info[0]) == LIGHT)
		f[1](index, obj);
	else if (attribut_identifier(info[0]) == AMBIENT_LIGHT)
		f[0](index, obj);*/
}
