/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/05 17:07:41 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		count;
	t_obj	**obj;

	obj = NULL;
	if (!is_valid(argc, argv))
		return (1);
	count = count_objs(argv);
	printf ("%d\n", count);
	obj = init_structs(obj, count);
	init_objets(obj, count, argv);
	free_objs(obj);
	//exit_message("Error/n", obj, 2);
	return (0);
}