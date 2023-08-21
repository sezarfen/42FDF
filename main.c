#include "fdf.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maph)
	{
		while (j < data->mapw)
		{
			printf("%3d", data->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	ft_printf("height -> %d\nwidth -> %d", data->maph, data->mapw);
}

void	init_values(t_data *data)
{
	data->winx = 1920;
	data->winy = 1080;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winx, data->winy, "fdf");
	data->angle = 0.8;
	data->zoom = 10;
	data->color = 0;
	data->shiftx = 400;
	data->shifty = 150;
	data->mode = 0;
	data->z_zoom = 1;
	printf("data angle-> %.2f\n", data->angle);
}

void	destroy_and_set(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	set_image_and_connect_indexes(data);
	mlx_do_sync(data->mlx);
}

int handle_key(int keycode, t_data *data)
{
	if (keycode == 126)
		data->zoom += 5;
	if (keycode == 125)
		data->zoom -= 5;
	if (keycode == 0)
		data->shiftx -= 30;
	if (keycode == 2)
		data->shiftx += 30;
	if (keycode == 1)
		data->shifty += 30;
	if (keycode == 13)
		data->shifty -= 30;
	if (keycode == 12)
		data->mode += 1;
	if (keycode == 14)
		data->z_zoom += 2;
	destroy_and_set(data);
	return (0);
}

int main(int ac, char **av)
{
	t_data *data;

	data = read_map(av[1]); // if there is av[1] (check that later)
	init_values(data);
	set_image_and_connect_indexes(data);
	mlx_hook(data->win, 2, 1L << 0 , handle_key, data);
	mlx_hook(data->win, 16, 1L << 0 , handle_key, data);
	mlx_loop(data->mlx);
	return (0);
}
