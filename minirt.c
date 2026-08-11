/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/11 15:11:19 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//DONE: arrange structs
//TODO: add a camera
//TODO: arrange pixel
//TODO: create mlx while

int	main(int argc, char **argv)
{
	int		count;
	t_world		w;

	ft_memset(&w, 0, sizeof(w));
	if (!is_valid(argc, argv))
		return (1);
	count = count_objs(argv, &w);
	printf("%d", count);
	init_structs(&w, count);
	init_objets(&w, count, argv);
	init_mlx(&w);
	exit_message("OK/n", &w, 1);
	return (0);
}