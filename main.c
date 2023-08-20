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
	ft_printf("height -> %d\n width -> %d", data->maph, data->mapw);
}

void	init_values(t_data *data)
{
	data->starter = 20;
	data->len_x = 20;
	data->len_y = 20;
}

int main(int ac, char **av)
{
	t_data *data;

	// 1. dosyayı oku
	data = read_map(av[1]); // if there is av[1] (check that later)
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 900, "fdf");

	init_values(data);
	// 2. bresenham kullanarak komşu indexler arasında çizgi çiz
	connect_indexes(data);

	// 3. isometrik görüntüyü ayarla
	
	mlx_loop(data->mlx);
	return (0);
}
