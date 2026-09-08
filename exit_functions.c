/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:31:40 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/08 14:50:14 by gcamara          ###   ########.fr       */
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

/*void	exit_setup_failure(t_world *w)
{
	free_double_ptr((void **)w->form, w->count_form);
	free(w->camera);
	free(w->ambient);
	exit(1);
}*/

void	exit_message(char *message, t_world *w, int code)
{
	write(code, message, ft_strlen(message));
	if (w->ambient)
		free(w->ambient);
	if (w->camera)
		free(w->camera);
	if (w->info)
		free_double_ptr((void **)w->info, count_tab(w->info));
	if (w->form)
		free_double_ptr((void **)w->form, w->count_form);
	if (w->lights)
		free_double_ptr((void **)w->lights, w->nb_lights);
	exit(code);
}
