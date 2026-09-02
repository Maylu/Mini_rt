/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:26:10 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/31 15:33:59 by gcamara          ###   ########.fr       */
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
	t_vector x;
	t_vector y;
	t_vector result;

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
				/*color pixel()
				t_vector hit_point = ray_position(w->camera->vec3, ray->dir, t);
				t_vector dir = vector_sub(w->light->vec3, hit_point);
				dir = normalise_vector(&dir);
				t_vector norm = get_normal(&w->obj_temp, hit_point);
				float dist = get_magnitude(vector_sub(w->light->vec3, hit_point));
				float t_shadow = vector_add(hit_point, vector_mult(norm, FLT_EPSILON));
				if (t_shadow > 0 && t_shadow < dist)
				{

				}*/
				my_mlx_pixel_put(&w->mlx, i, j, pixel_color(w, ray, t));
			else
				my_mlx_pixel_put(&w->mlx, i, j, 0x000000FF);
			j++;
		
		}
		i++;
	}
}



void	is_hitting(t_world *w, t_ray *ray, float *t)
{
	int	i;
	int inter;
	float temp;
	float t_local;

	i = 0;
	w->hit = 0;
	temp = FLT_MAX;
	while (w->form[i] != NULL)
	{
		t_local = FLT_MAX; //chaque objet a son propre t, isolé, pour ne pas modifier le t des autres
		inter = 0;
		if (w->form[i]->identifier == SPHERE)
			//inter = intersect_sphere(ray, w->form[i], t);
			inter = intersect_sphere(ray, w->form[i], &t_local);
		else if (w->form[i]->identifier == PLANE)
			//inter = intersect_plane(ray, w->form[i], t);
			inter = intersect_plane(ray, w->form[i], &t_local);
		else if (w->form[i]->identifier == CYLINDER)
			//inter = intersect_cylinder(ray, w->form[i], t);
			inter = intersect_cylinder(ray, w->form[i], &t_local);
		//if (*t < temp && inter == 1)
		if (t_local < temp && inter == 1)
		{
			temp = t_local;
			//temp = *t;
			w->obj_temp = *w->form[i];
			w->hit = 1;
		} // risque de t continuer à avoir la valeur du dernier obj testé
		i++;
	}
	if (w->hit)
		*t = temp; // à la fin, *t reçois le plus petit temp
}