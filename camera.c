/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:01:18 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/10 16:25:23 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void set_viewport(t_scene *s)
{
    float ratio;
    int i_width = WIDTH;
    int i_height = i_width / ratio;
    if (i_height < 1)
        i_height = 1;
    int v_width = 2.0;
    int v_height = v_height * (i_width / i_height);

    t_vector u;
    u.x = v_width;
    u.y = 0;
    u.z = 0;
    t_vector v;
    u.x = 0;
    u.y = -v_height;
    u.z = 0;
}

void set_camera(t_scene *s)
{

}
/*❶Place the camera and the viewport as desired
For each pixel on the canvas
480 x 270
    ❷Determine which square on the viewport corresponds to this pixel
    ❸Determine the color seen through that square
    ❹Paint the pixel with that color*/