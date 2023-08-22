#include "fdf.h"

int	set_color(float z, t_data *data) // RENKLER BOZUK, TEKRAR BAKILMASI LAZIM
{
	float	max_z;
	float	min_z;
	float	ratio;

	max_z = get_max_z(data);
	min_z = get_min_z(data);
	ratio = max_z - min_z;
	if (z > ratio / 1.5)
		return(0XFFFFFF);
	else if (z > ratio / 2)
		return(0X800020);
	else if (z > ratio / 3)
		return(0x964B00);
	else if (z > ratio / 4)
		return(0X04FF00);
	else if (z > ratio / 5)
		return(0x009DC4);
	else
		return(0X0000FF);
}

void	init_colors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->colors = malloc(sizeof(int **) * data->maph);
	while (i < data->maph)
	{
		data->colors[i] = malloc(sizeof(int *) * data->mapw);
		while (j < data->mapw)
		{
			data->colors[i][j] = set_color(data->map[i][j], data);
			j++;
		}
		i++;
		j = 0;
	}
}