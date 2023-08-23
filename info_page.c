/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:12 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:41:55 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	paint_background(t_data *data)
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
}

void	set_info_page(t_data *data, char **av)
{
	paint_background(data);
	mlx_string_put(data->mlx, data->win, 30, 100, 0X04D9FF, "Keys:");
	mlx_string_put(data->mlx, data->win, 30, 150,
		0XFFFFFF, "W A S D - Translation");
	mlx_string_put(data->mlx, data->win, 30, 200, 0XFFFFFF, "UP KEY - Zoom In");
	mlx_string_put(data->mlx, data->win, 30, 250,
		0XFFFFFF, "DOWN KEY - Zoom Out");
	mlx_string_put(data->mlx, data->win, 30, 300, 0XFFFFFF, "R - change z (+)");
	mlx_string_put(data->mlx, data->win, 30, 350, 0XFFFFFF, "E - change z (-)");
	mlx_string_put(data->mlx, data->win, 30, 400, 0XFFFFFF, "Q - change mode");
	mlx_string_put(data->mlx, data->win, 30, 500, 0X04D9FF, "Current map:");
	mlx_string_put(data->mlx, data->win, 20, 530, 0xFFFFFF, av[1]);
}
