/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:36:59 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/30 16:59:21 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_objs(char **argv)
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
		if (attribut_identifier(tab[0]) != 0)
			count++;
		free_tab(tab);
		free (line);
		line = NULL;
	}
	close (file);
	return (count);
}

t_obj	**init_structs(t_obj **obj, int count)
{
	int	i;

	i = 0;
	obj = malloc(sizeof(t_obj *) * (count + 1));
	if (obj == NULL)
		exit(1);
	while (i < count)
	{
		obj[i] = malloc(sizeof(t_obj));
		if (obj[i] == NULL)
			exit(1);
		ft_memset(obj[i], 0, sizeof(t_obj));
		i++;
	}
	obj[i] = NULL;
	return (obj);
}

void	init_objets(t_obj **obj, int count, char **argv)
{
	int		file;
	char	*line;
	int		i;

	(void)count;
	i = 0;
	file = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break ;
		obj[i]->info = ft_split(line, '\t');
		attribute_info(obj[i]);
		free_tab(obj[i]->info);
		free (line);
		line = NULL;
	}
	close (file);
}

void	attribute_info(t_obj *obj)
{
	atributs	f[6];
	int			i;

	i = 0;
	f[0] = &add_ambiant;
	f[1] = &add_light;
	f[2] = &add_camera;
	f[3] = &add_sphere;
	f[4] = &add_plane;
	f[5] = &add_cylindre;

	while (i < 6)
	{
		if (i == attribut_identifier(obj->info[0]))
			f[i]();
		i++;
	}
}
