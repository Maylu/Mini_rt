/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:56:48 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/11 14:13:48 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_world *w)
{
	if (w->mlx.img)
		mlx_destroy_image(w->mlx.mlx, w->mlx.img);
	if (w->mlx.mlx_win)
		mlx_destroy_window(w->mlx.mlx, w->mlx.mlx_win);
	mlx_destroy_display(w->mlx.mlx);
	free(w->mlx.mlx);
	exit_message("OK", w, 0);
	return (0);
}

int	move_window(int keycode, t_world *w)
{
	if (keycode == XK_Escape)
	{
		if (w->mlx.img)
			mlx_destroy_image(w->mlx.mlx, w->mlx.img);
		if (w->mlx.mlx_win)
			mlx_destroy_window(w->mlx.mlx, w->mlx.mlx_win);
		mlx_destroy_display(w->mlx.mlx);
		free(w->mlx.mlx);
		exit_message("OK", w, 0);
	}
	return (0);
}

void	init_mlx(t_world *w)
{
	int i;
	int j;

	i = 0;
	j = 0;
	w->mlx.mlx = mlx_init();
	w->mlx.mlx_win = mlx_new_window(w->mlx.mlx, 500, 500, "Minirt");
	w->mlx.img = mlx_new_image(w->mlx.mlx, 500, 500);
	w->mlx.addr = mlx_get_data_addr(w->mlx.img, &w->mlx.bits_per_pixel, &w->mlx.line_length, &w->mlx.endian);
	while(i < 500)
	{
		j = 0;
		while (j < 500)
		{
			my_mlx_pixel_put(&w->mlx, i, j, 0x00FF0000);
			++j;		//exit_message("Closed\n", w->objs, 0);

		}
		++i;
	}
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.mlx_win, w->mlx.img, 0, 0);
	mlx_hook(w->mlx.mlx_win, 17, 0, (void*)close_window, w);
	mlx_hook(w->mlx.mlx_win, 2, 1, (void*)move_window, w);
	mlx_loop(w->mlx.mlx);
}
