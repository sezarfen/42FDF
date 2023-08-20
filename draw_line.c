#include "fdf.h"

void	bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
	float	dx; // change in x
	float	dy; // change in y
	int	cmax; // maximum change

	dx = x2 - x1; // dx ve dy
	dy = y2 - y1; // bu kısımda negative olabilirler
	cmax = max(abs(dx), abs(dy)); // burada değişim olarak absolute değerlerini dikkate alacağız
	
	dx = dx / cmax;
	dy = dy / cmax;
	while (x1 < x2 || abs(y1 - y2) > 0)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, 0xffffff);
		x1 += dx;
		y1 += dy;
	}
}

void	connect_indexes(t_data *data)
{
	int	h;
	int	w;
	int	s;

	s = data->starter;
	h = 0;
	w = 0;
	while (h < data->maph) // data->starter burada da olmalı ki, başlagınçta direkt data->maph yi geçmesin
	{
		while (w < data->mapw)
		{
			if (w != data->mapw - 1) // sağa doğru çizgi
				bresenham(w * s, h * s, (w + 1) * s, h * s, data);
			if (h != data->maph - 1) // aşağı doğru çizgi
				bresenham(w * s, h * s, w * s, (h + 1) * s, data);
			w++;
		}
		w = 0;
		h++;
	}
}