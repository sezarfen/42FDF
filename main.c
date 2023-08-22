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
	data->change_color = 1;
	data->shiftx = 400;
	data->shifty = 150;
	data->mode = 0;
	data->z_zoom = 1;
}

void	destroy_and_set(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	set_image_and_connect_indexes(data);
	mlx_do_sync(data->mlx);
}

int handle_key(int keycode, t_data *data)
{
	// fonksiyonu ortadan 2 ye bölme yapabiliriz
	if (keycode == 126)
		data->zoom += 3;
	if (keycode == 125)
		data->zoom -= 3;
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
	if (keycode == 15)
		data->z_zoom += 1.2;
	if (keycode == 14)
		data->z_zoom -= 1.2;
	if (keycode == 53)
		exit(0);
	destroy_and_set(data);
	return (0);
}

int	destroy(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_data *data;
	
	if (ac == 2)
	{
		check_up(ac, av);
		data = read_map(av[1]);
		init_colors(data);
		init_values(data);
		set_info_page(data);
		set_image_and_connect_indexes(data);
		mlx_hook(data->win, 2, 1L << 0 , handle_key, data);
		mlx_hook(data->win, 17, 1L, destroy, data);
		mlx_loop(data->mlx);
	}
	ft_printf("Eksik veya fazla arguman girisi yaptiniz.\n");
	return (0);
}
