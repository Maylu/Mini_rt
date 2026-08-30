/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmontei <rhmontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/27 03:49:28 by rhmontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//DONE: arrange structs
//DONE: add a camera
//DONE: arrange pixel
//DONE: create mlx while

//TODO: apply shadow
//TODO:	apply light
//TODO: 
//TODO:


int	main(int argc, char **argv)
{
	int			count;
	t_world		w;

	ft_memset(&w, 0, sizeof(w));
	if (!is_valid(argc, argv))
		return (1);
	count = count_objs(argv, &w);
	printf("%d", count);
	init_structs(&w, count);
	init_objets(&w, argv);
	init_mlx(&w);
	exit_message("OK/n", &w, 1); // code 1 ?
	return (0);
}