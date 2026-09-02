/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:36:59 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/30 16:51:41 by gcamara          ###   ########.fr       */
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
		tab = ft_split_charset(line, "\t ");
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


void	init_objets(t_world *w, char **argv)
{
	int		file;
	char	*line;

	file = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		line = clean_line(&line);
		w->info = ft_split_charset(line, "\t ");
		if (w->info[0] == NULL || attribut_identifier(w->info[0]) < 0 )
		{
			clean_memory(w, &line);
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
	close (file);
}

void	attribute_info(int type, t_world *w)
{
	t_atributs	f[6];
	printf("%d\n", type);
	f[0] = &add_ambiant;
	f[1] = &add_light;
	f[2] = &add_camera;
	f[3] = &add_sphere;
	f[4] = &add_plane;
	f[5] = &add_cylindre;

	f[type](w);
}
