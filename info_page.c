#include "fdf.h"

void	set_info_page(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 1080)
	{
		while (j < 300)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, 0X1B1212);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_string_put(data->mlx, data->win, 30, 100, 0XFFFFFF, "Keys:");
	mlx_string_put(data->mlx, data->win, 30, 150, 0XFFFFFF, "W A S D - Translation");
	mlx_string_put(data->mlx, data->win, 30, 200, 0XFFFFFF, "UP KEY - Zoom In");
	mlx_string_put(data->mlx, data->win, 30, 250, 0XFFFFFF, "DOWN KEY - Zoom Out");
	mlx_string_put(data->mlx, data->win, 30, 300, 0XFFFFFF, "R - change z (+)");
	mlx_string_put(data->mlx, data->win, 30, 350, 0XFFFFFF, "E - change z (-)");
	mlx_string_put(data->mlx, data->win, 30, 400, 0XFFFFFF, "Q - projection mode");
}