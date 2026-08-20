/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:56:48 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/18 18:47:10 by gcamara          ###   ########.fr       */
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

t_vector	calculate_pixel(t_world *w, int i, int j, t_vector view_up_right)
{
	t_vector x;
	t_vector y;
	t_vector result;

	x = vector_mult(w->right_vec, (w->pixel_u * (float)i));
	y = vector_mult(w->up_vec, (w->pixel_v * (float)j));
	result = vector_sub(x, y);
	result = vector_add(view_up_right, result);
	return (result);
}

int color(t_obj *obj)
{
	return (256 * 256 * obj->color.r + 256 * obj->color.g + obj->color.b);
}

void	init_mlx(t_world *w)
{
	int i;
	int j;
	t_vector view_up_right;
	t_ray ray;
	float test = 0;
	i = 0;
	j = 0;
	int k = 0;
	int inter = 0;
	float temp;
	t_obj obj;
	ray.o = w->camera->vec3;
	view_up_right = set_viewport_up_right(w);
	w->pixel_u = w->v_width / (float)w->mlx.w;
	w->pixel_v = w->v_height / (float)w->mlx.h;
	w->mlx.mlx = mlx_init();
	w->mlx.mlx_win = mlx_new_window(w->mlx.mlx, w->mlx.w, w->mlx.h, "Minirt");
	w->mlx.img = mlx_new_image(w->mlx.mlx,  w->mlx.w,  w->mlx.h);
	w->mlx.addr = mlx_get_data_addr(w->mlx.img, &w->mlx.bits_per_pixel, &w->mlx.line_length, &w->mlx.endian);
	while(i < w->mlx.w)
	{
		j = 0;
		while (j < w->mlx.h)
		{
			int hit = 0;
			k = 0;
			temp = FLT_MAX;
			ray.pixel_space = calculate_pixel(w, i, j, view_up_right);
			ray.dir = vector_sub (ray.pixel_space, w->camera->vec3);
			ray.dir = normalise_vector(&ray.dir);
			while (w->form[k] != NULL)
			{
				inter = 0;
				if (w->form[k]->identifier == SPHERE)
					inter = intersect_sphere(&ray, w->form[k], &test);
			//	else if (w->form[k].identifier == PLANE)
			//		inter = intersect_plane(&ray, w->form[k], &test) == 1;
			//	else if (w->form[k].identifier == CYLINDER)
			//		inter = intersect_cylinder(&ray, w->form[k], &test) == 1;
				if (test < temp && inter == 1)
				{
					temp = test;
					obj = *w->form[k];
					hit = 1;
				}
				k++;
			}
			if(hit)
				my_mlx_pixel_put(&w->mlx, i, j, color(&obj));
			else
				my_mlx_pixel_put(&w->mlx, i, j, 0x000000FF);
			/*if (intersect_sphere(&ray, w->form[1], &test) == 1)
				my_mlx_pixel_put(&w->mlx, i, j, color(w->form[1]));
			else if (intersect_sphere(&ray, w->form[1], &test) == 0)
				my_mlx_pixel_put(&w->mlx, i, j, 0x000000FF);*/
			j++;

		}
		i++;
	}
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.mlx_win, w->mlx.img, 0, 0);
	mlx_hook(w->mlx.mlx_win, 17, 0, (void*)close_window, w);
	mlx_hook(w->mlx.mlx_win, 2, 1, (void*)move_window, w);
	mlx_loop(w->mlx.mlx);
}
