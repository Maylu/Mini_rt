/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinate_others.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 12:18:16 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/21 12:20:30 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (!(ft_isdigit(str[i + 1]))))
			return (0);
		i++;
	}
	return (1);
}

void	check_point(t_world *w, char *c, int *point)
{
	if (*c == '.' && *point == 1)
		exit_message("bad arguments2", w, 2);
	if (*c == '.')
		*point = 1;
}

void	check_characters(t_world *w, char *c, int flag)
{
	if (flag == 1)
	{
		if (!ft_isdigit(*c) && *c != ',' && *c != '.'
			&& *c != '+' && *c != '-')
			exit_message("bad arguments1", w, 2);
	}
	else if (flag == 0)
	{
		if (!ft_isdigit(*c) && *c != '.'
			&& *c != '+' && *c != '-')
			exit_message("bad arguments1", w, 2);
	}
}

void	check_value_coordinate(char *str, t_world *w, int flag)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (flag == 1)
	{
		while (str[i] != '\0')
		{
			check_point(w, &str[i], &point);
			check_characters(w, &str[i], flag);
			if (str[i] == ',' || str[i + 1] == '\0')
				point = 0;
			i++;
		}
	}
	else if (flag == 0)
	{
		while (str[i] != '\0')
		{
			check_point(w, &str[i], &point);
			check_characters(w, &str[i], flag);
			i++;
		}
	}
}

float	set_fov(t_world *w, int cat)
{
	float	result;

	check_value_coordinate(w->info[cat], w, 0);
	if (!count_sign(w->info[cat]))
		exit_message("bad argument size", w, 2);
	result = ft_atof(w->info[cat]);
	if (isinf(result))
		exit_message("bad argument fov", w, 2);
	if (result < 0.f || result > 180.f)
		exit_message("bad argument fov", w, 2);
	return (result);
}