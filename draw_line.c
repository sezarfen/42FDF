#include "fdf.h"

void	set_projection(float *x, float *y, float *z, t_data *data)
{
	if (data->mode % 3 == 0)
		isometric(x, y, z, data);
	else if (data->mode % 3 == 1)
		parallel(x, y, z, data);
	else if (data->mode % 3 == 2)
		conic(x, y, z, data);
}

void	bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
	float	dx;
	float	dy;
	float	z1;
	float	z2;
	int		cmax;

	z1 = data->map[((int)y1)][((int)x1)];
	z2 = data->map[((int)y2)][((int)x2)];
	data->color = data->colors[((int)y1)][((int)x1)];
	zoom(&x1, &y1, &x2, &y2, data);
	zoom_z(&z1, &z2, data);
	set_projection(&x1, &y1, &z1, data);
	set_projection(&x2, &y2, &z2, data);
	set_indexes(&x1, &y1, &x2, &y2, data);
	dx = x2 - x1;
	dy = y2 - y1;
	cmax = max(fabs(dx), fabs(dy));
	dx = dx / cmax;
	dy = dy / cmax;
	while ((int)(x1 - x2)|| (int)(y1 - y2))
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
	while (h < data->maph) // data->starter burada da olmalı ki, başlagınçta direkt data->maph yi geçmesin
	{
		while (w < data->mapw)
		{
			if (w < data->mapw - 1) // sağa doğru çizgi
				bresenham(w, h, w + 1, h, data); // "+ s" ile sağ üstten daha aşağıda başlıyor 
			if (h < data->maph - 1) // aşağı doğru çizgi
				bresenham(w, h, w, h + 1, data);
			w++;
		}
		w = 0;
		h++;
	}
}

void	set_image_and_connect_indexes(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 1620, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	connect_indexes(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 300, 0);
}