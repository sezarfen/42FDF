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


int main(int ac, char **av)
{
	t_data *data;

	data = read_map(av[1]); // if there is av[1] (check that later)
	print_map(data);
	return (0);
}
