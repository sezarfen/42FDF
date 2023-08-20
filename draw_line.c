#include "fdf.h"

void	draw_line_in(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int slope = abs(y2 - y1) / abs(x2 - x1);
	int temp_slope = slope;
	if (slope == 0)
		slope = 1;
	if (x1 < x2)
	{
		while (x1 < x2)
		{
			if (y1 < y2)
			{
				mlx_pixel_put(mlx, win, x1++, y1, 0XFFFFFF);
				while (temp_slope--)
					mlx_pixel_put(mlx, win, x1, y1++, 0XFFFFFF);
				temp_slope = slope;
			}
			else
			{
				mlx_pixel_put(mlx, win, x1++, y2, 0XFFFFFF);
				while (temp_slope--)
					mlx_pixel_put(mlx, win, x1, y2++, 0XFFFFFF);
				temp_slope = slope;
			}
		}
	}
	else
	{
		while (x2 < x1)
		{
			if (y1 < y2)
			{
				mlx_pixel_put(mlx, win, x2++, y1, 0XFFFFFF);
				while (temp_slope--)
					mlx_pixel_put(mlx, win, x2, y1++, 0XFFFFFF);
				temp_slope = slope;
			}
			else
			{
				mlx_pixel_put(mlx, win, x2++, y2, 0XFFFFFF);
				while (temp_slope--)
					mlx_pixel_put(mlx, win, x2, y2++, 0XFFFFFF);
				temp_slope = slope;
			}
		}
	}
}
/*
int main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 900, "New Window");

	draw_line_in(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), mlx, win);
	
	mlx_loop(mlx);
}
*/
// (x1, y1) -> (x2, y2)