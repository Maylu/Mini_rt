/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:36:59 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/03 21:16:08 by gcamara          ###   ########.fr       */
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
		if (attribut_identifier(tab[0]) < 0)
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

char 	*clean_line(char **line)
{
	int len;

	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return(*line);
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
		line = clean_line(&line);
		obj[i]->info = ft_split(line, '\t');
		if (obj[i]->info[0] == NULL || attribut_identifier(obj[i]->info[0]) < 0 )
		{
			free_tab(obj[i]->info);
			free(line);
			continue;
		}
		free (line);
		line = NULL;
		i++;
	}
	for (int j = 0;  obj[j]; j++)
	{
		attribute_info(j, obj);
	}
	printf("Sphere:\n");
	printf("  Diameter : %f\n", obj[4]->diameter);
	printf("  Position : x = %f, y = %f, z = %f\n",
    obj[4]->vec3.x, obj[4]->vec3.y, obj[4]->vec3.z);
	printf("  Color    : r = %f, g = %f, b = %f\n",
    obj[4]->color.r, obj[4]->color.g, obj[4]->color.b);
	close (file);
}

void	attribute_info(int index, t_obj **obj)
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
		if (i == attribut_identifier(obj[index]->info[0]))
			f[i](index, obj);
		i++;
	}
}
