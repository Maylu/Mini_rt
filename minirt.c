/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/24 18:00:23 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/GNL/get_next_line.h"
#include "Includes/libft/libft.h"

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

int	main(int argc, char **argv)
{
	if (!is_valid(argc, argv))
		return (1);
	init_objets();
		//exit_message(2, "Error/n");
	return (0);
}