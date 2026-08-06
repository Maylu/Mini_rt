/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:56:48 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/06 15:17:09 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(t_data *img)
{
	(void)img;
	exit(0);
	//exit_message("Closed\n", &g, 0);
	return (0);
}

int	move_window(int keycode, t_data *img)
{
	(void)img;
	if (keycode == XK_Escape)
		exit(0);
		//exit_message("Closed\n", &g, 0);
	return (0);
}

void	init_mlx(void)
{
	t_data	img;
	int i;
	int j;

	i = 0;
	j = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(img.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(i < 500)
	{
		j = 0;
		while (j < 500)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 17, 0, (void*)close_window, &img);
	mlx_hook(img.mlx_win, 2, 1, (void*)move_window, &img);
	mlx_loop(img.mlx);
}
