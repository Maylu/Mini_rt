/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:40:01 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/31 14:48:34 by gcamara          ###   ########.fr       */
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

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int attribut_identifier(char *identifier)
{
	if(strcmp(identifier, "L") == 0)
		return (LIGHT);
	else if(strcmp(identifier, "C") == 0)
		return (CAMERA);
	else if(strcmp(identifier, "A") == 0)
		return (AMBIENT_LIGHT);
	else if(strcmp(identifier, "sp") == 0)
		return (SPHERE);
	else if(strcmp(identifier, "pl") == 0)
		return (PLANE);
	else if(strcmp(identifier, "cy") == 0)
		return (CYLINDER);
	return (-1);
}
