/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:26:10 by gcamara           #+#    #+#             */
/*   Updated: 2026/09/08 19:03:06 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length)
		+ (x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_vector	calculate_pixel(t_world *w, int i, int j, t_vector view_up_right)
{
	t_vector	x;
	t_vector	y;
	t_vector	result;

	w->pixel_u = w->v_width / (float)w->mlx.w;
	w->pixel_v = w->v_height / (float)w->mlx.h;
	x = vector_mult(w->right_vec, (w->pixel_u * (float)i));
	y = vector_mult(w->up_vec, (w->pixel_v * (float)j));
	result = vector_sub(x, y);
	result = vector_add(view_up_right, result);
	return (result);
}

void	put_pixel(t_world *w, t_vector *view_up_right, t_ray *ray)
{
	int			i;
	int			j;
	float		t;

	i = 0;
	j = 0;
	t = 0;
	while (i < w->mlx.w)
	{
		j = 0;
		while (j < w->mlx.h)
		{
			ray->pixel_space = calculate_pixel(w, i, j, *view_up_right);
			ray->dir = vector_sub (ray->pixel_space, w->camera->vec3);
			ray->dir = normalise_vector(&ray->dir);
			is_hitting (w, ray, &t);
			if (w->hit)
				my_mlx_pixel_put(&w->mlx, i, j, pixel_color(w, ray, t));
			else
				my_mlx_pixel_put(&w->mlx, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	is_hitting(t_world *w, t_ray *ray, float *t)
{
	int		i;
	int		inter;
	float	temp;

	i = 0;
	w->hit = 0;
	temp = FLT_MAX;
	while (w->form[i] != NULL)
	{
		w->t_local = FLT_MAX;
		inter = 0;
		if (w->form[i]->identifier == SPHERE)
			inter = intersect_sphere(ray, w->form[i], &w->t_local);
		else if (w->form[i]->identifier == PLANE)
			inter = intersect_plane(ray, w->form[i], &w->t_local);
		else if (w->form[i]->identifier == CYLINDER)
			inter = intersect_cylinder(ray, w->form[i], &w->t_local);
		temp_hit(i, &temp, inter, w);
		i++;
	}
	if (w->hit)
		*t = temp;
}

void	temp_hit(int i, float *temp, int inter, t_world *w)
{
	if (w->t_local < *temp && inter == 1)
	{
		*temp = w->t_local;
		w->obj_temp = *w->form[i];
		w->hit = 1;
	}
}
