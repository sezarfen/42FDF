/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:07 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 17:45:37 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(float x1, float y1, float x2, t_data *data)
{
	float	dx;
	float	dy;
	float	z1;
	float	z2;
	int		cmax;

	z1 = data->map[(int)y1][(int)x1];
	z2 = data->map[(int)data->y2][(int)x2];
	data->color = data->colors[((int)y1)][((int)x1)];
	zoom(&x1, &y1, &x2, data);
	zoom_z(&z1, &z2, data);
	set_projection(&x1, &y1, &z1, data);
	set_projection(&x2, &data->y2, &z2, data);
	set_indexes(&x1, &y1, &x2, data);
	dx = x2 - x1;
	dy = data->y2 - y1;
	cmax = max(fabs(dx), fabs(dy));
	dx = dx / cmax;
	dy = dy / cmax;
	while ((int)(x1 - x2) || (int)(y1 - data->y2))
	{
		my_mlx_pixel_put(data, x1, y1, data->color);
		x1 += dx;
		y1 += dy;
	}
}

void	connect_indexes(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < data->maph)
	{
		while (w < data->mapw)
		{
			if (w < data->mapw - 1)
			{
				data->y2 = h;
				bresenham(w, h, w + 1, data);
			}
			if (h < data->maph - 1)
			{
				data->y2 = h + 1;
				bresenham(w, h, w, data);
			}
			w++;
		}
		w = 0;
		h++;
	}
}

void	set_image_and_connect_indexes(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 1620, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
			&data->line_length, &data->endian);
	connect_indexes(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 300, 0);
}
