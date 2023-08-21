#include "fdf.h"

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	int	i;

	i = split_len(split) - 1;
	while (i >= 0)
	{
		free(split[i]);
		split[i] = NULL;
		i--;
	}
	free(split);
	split = NULL;
}

int max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < data->winx && x > 0) && (y < data->winy && y > 0)) // bu sayede dışarı taşan pixeller çizdirilmiyor
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}