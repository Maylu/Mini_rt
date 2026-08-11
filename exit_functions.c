/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:31:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/11 15:11:00 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void exit_message(char *message, t_world *w, int code)
{
	write(code, message, ft_strlen(message));
	free(w->ambient);
	free(w->light);
	free(w->camera);
	if(w->info)
		free_tab(w->info);
	free_objs(w->form);
	exit(code);
}
