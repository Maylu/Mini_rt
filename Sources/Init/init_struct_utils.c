/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:37:43 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/08 15:58:14 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*clean_line(char **line)
{
	int	len;

	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (*line);
}

void	check_doubles(t_world *w, char *tab)
{
	if (attribut_identifier(tab) == CAMERA)
		w->is_camera++;
	if (attribut_identifier(tab) == LIGHT)
		w->is_light++;
	if (attribut_identifier(tab) == AMBIENT_LIGHT)
		w->is_ambient++;
}

void	clean_memory(t_world *w, char **line)
{
	free_double_ptr((void **)w->info, count_tab(w->info));
	w->info = NULL;
	free(*line);
	*line = NULL;
}
