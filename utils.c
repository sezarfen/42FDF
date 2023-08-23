/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:21 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:47:28 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i--;
	}
	free(split);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < data->winx - 300 && x > 0) && (y < data->winy && y > 0))
	{
		if (data->zoom > 0)
		{
			dst = data->addr + 
				(y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
}

int	get_max_z(t_data *data)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = data->map[i][j];
	while (i < data->maph)
	{
		while (j < data->mapw)
		{
			if (max < data->map[i][j])
				max = data->map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (max);
}

int	get_min_z(t_data *data)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = data->map[i][j];
	while (i < data->maph)
	{
		while (j < data->mapw)
		{
			if (min > data->map[i][j])
				min = data->map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (min);
}
