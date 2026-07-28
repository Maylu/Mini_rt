/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/28 19:34:15 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((p1[i] != '\0') && (p1[i] == p2[i]))
	{
		i++;
	}
	return (p1[i] - p2[i]);
}

int	is_valid(int argc, char **argv)
{
	char	*temp;

	if (argc > 2)
		return (0);
	if (ft_strchr(argv[1], '.') != 0)
	{
		temp = ft_strchr(argv[1], '.');
		if (ft_strcmp(temp, ".rt") != 0)
			return (0);
	}
	return (1);
}

int count_objs(char **argv)
{
	int file;
	int count;
	char *line;

	count = 0;
	file = open(argv[1], O_RDONLY);
	while(1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break;
		free (line);
		line = NULL;
		count++;
	}
	close (file);
	return(count);
}

t_obj **init_structs(t_obj **obj, int count)
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
		memset(obj[i], 0, sizeof(t_obj));
		i++;
	}
	obj[i] = NULL;
	return(obj);
}

init_objets(t_obj **obj, int count, char **argv)
{
	int file;
	char *line;
	int i;

	i = 0;
	file = open(argv[1], O_RDONLY);
	while(1)
	{
		line = get_next_line(file);
		if (line == NULL)
			break;
		obj[i]->info = ft_split(line, "\t");
		attribute_info(obj[i]);
		free (line);
		line = NULL;
	}
	close (file);
}

void attribut_identifier(t_obj *obj, char *identifier)
{
	if(strcmp(identifier, "L"))
		obj->identifier = LIGHT;
	else if(strcmp(identifier, "C"))
		obj->identifier = CAMERA;
	else if(strcmp(identifier, "A"))
		obj->identifier = AMBIENT_LIGHT;
	else if(strcmp(identifier, "sp"))
		obj->identifier = SPHERE;
	else if(strcmp(identifier, "pl"))
		obj->identifier = PLANE;
	else if(strcmp(identifier, "cy"))
		obj->identifier = CYLINDER;
}

void free_objs(t_obj **obj)
{
	int i;

	i = 0;
	while (obj[i])
	{
		free(obj[i]);
		i++;
	}
	free(obj);
}


void exit_message(char *message, t_obj **obj, int code)
{
	write(code, message, ft_strlen(message));
	free_objs(obj);
}

int	main(int argc, char **argv)
{
	int count;
	t_obj **obj;

	obj = NULL;
	if (!is_valid(argc, argv))
		return (1);	
	count = count_objs(argv);
	obj = init_structs(obj, count);
	init_objets(obj, count, argv);
	exit_message("Error/n", obj, 2);
	return (0);
}