/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:31:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/03 03:36:49 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_double_ptr(void **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_objs(t_obj **obj)
{
	int	i;

	i = 0;
	while (obj[i])
	{
		free(obj[i]);
		i++;
	}
	free(obj);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_setup_failure(t_world *w)
{
	free_ptr_array((void **)w->form, w->count_form);
	free(w->camera);
	free(w->ambient);
	exit(1);
}

void	exit_message(char *message, t_world *w, int code)
{
	write(code, message, ft_strlen(message));
	free(w->ambient);
	free_tab(w->lights);
	free(w->camera);
	if (w->info)
		free_tab(w->info);
	// free_objs(w->form);
	free_tab(w->form);
	exit(code);
}
