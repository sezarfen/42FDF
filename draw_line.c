#include "fdf.h"

void	zoom(float *x1, float *y1, float *x2, float *y2, t_data *data)
{
	// --zoom-- (30)    // default    	   zoomed
	*x1 *= data->zoom;	// 10         ->    300
	*x2 *= data->zoom;	// 10         ->    300
	*y1 *= data->zoom;	// 100        ->    3000
	*y2 *= data->zoom;	// 200        ->    3000
}

void	change_color(int z, t_data *data)
{
	if (z == 0)
		data->color = 0XFFFFFF;
	else
		data->color =  z * 0x00FF00;
}

void	bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
	float	dx; 	// change in x
	float	dy; 	// change in y
	int		cmax;	// maximum change
	float		z1;
	float		z2;

	z1 = data->map[((int)y1)][((int)x1)];
	z2 = data->map[((int)y2)][((int)x2)];
	// --zoom--
	zoom(&x1, &y1, &x2, &y2, data);
	// --color--
	change_color(z1, data);
	// --isometric projection (3D)--
	isometric(&x1, &y1, &z1, data);
	isometric(&x2, &y2, &z2, data);
	// --shifting--
	x1 += data->shiftx;
	y1 += data->shifty;
	x2 += data->shiftx;
	y2 += data->shifty;

	dx = x2 - x1; // dx ve dy
	dy = y2 - y1; // bu kısımda negative olabilirler
	cmax = max(fabs(dx), fabs(dy)); // burada değişim olarak absolute değerlerini dikkate alacağız
	
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
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	connect_indexes(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}