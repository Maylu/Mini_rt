/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:50 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/08 15:58:54 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int			count;
	t_world		w;

	ft_memset(&w, 0, sizeof(w));
	if (!is_valid(argc, argv))
	{
		write(2, "file not valid", 15);
		return (2);
	}
	count = count_objs(argv, &w);
	init_structs(&w, count);
	init_objets(&w, argv);
	init_mlx(&w);
	exit_message("OK/n", &w, 0);
	return (0);
}
