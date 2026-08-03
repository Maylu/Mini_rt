/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:31:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/03 19:19:30 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_objs(t_obj **obj)
{
	int i;

	i = 0;
	while (obj[i])
	{
		free_tab(obj[i]->info);
		free(obj[i]);
		i++;
	}
	free(obj);
	exit(2);
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void exit_message(char *message, t_obj **obj, int code)
{
	write(code, message, ft_strlen(message));
	free_objs(obj);
}
