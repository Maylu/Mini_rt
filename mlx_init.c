/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:56:48 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/24 17:31:24 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
	t_vector	view_up_right;
	t_ray		ray;

	ray.o = w->camera->vec3;
	view_up_right = set_viewport_up_right(w);
	w->mlx.mlx = mlx_init();
	w->mlx.mlx_win = mlx_new_window(w->mlx.mlx, w->mlx.w, w->mlx.h, "Minirt");
	w->mlx.img = mlx_new_image(w->mlx.mlx,  w->mlx.w,  w->mlx.h);
	w->mlx.addr = mlx_get_data_addr(w->mlx.img, &w->mlx.bits_per_pixel,
			&w->mlx.line_length, &w->mlx.endian);
	put_pixel(w, &view_up_right, &ray);
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.mlx_win, w->mlx.img, 0, 0);
	mlx_hook(w->mlx.mlx_win, 17, 0, (void *)close_window, w);
	mlx_hook(w->mlx.mlx_win, 2, 1, (void *)move_window, w);
	mlx_loop(w->mlx.mlx);
}