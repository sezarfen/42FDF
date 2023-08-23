/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:14 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:42:31 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_color(float z, t_data *data)
{
	float	max_z;
	float	min_z;
	float	ratio;

	max_z = get_max_z(data);
	min_z = get_min_z(data);
	ratio = max_z - min_z;
	if (z > ratio / 1.5)
		return (0XFFFFFF);
	else if (z > ratio / 2)
		return (0X8B0000);
	else if (z > ratio / 3)
		return (0x964B00);
	else if (z > ratio / 4)
		return (0X236F21);
	else if (z > ratio / 5)
		return (0x009DC4);
	else
		return (0X0000FF);
}

void	init_colors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->colors = malloc(sizeof(int *) * data->maph + 1);
	while (i < data->maph)
	{
		data->colors[i] = malloc(sizeof(int) * data->mapw + 1);
		while (j < data->mapw)
		{
			data->colors[i][j] = set_color(data->map[i][j], data);
			j++;
		}
		i++;
		j = 0;
	}
}
