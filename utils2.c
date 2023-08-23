/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:23 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 17:43:51 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(float *x1, float *y1, float *x2, t_data *data)
{
	*x1 *= data->zoom;
	*x2 *= data->zoom;
	*y1 *= data->zoom;
	data->y2 *= data->zoom;
}

void	set_indexes(float *x1, float *y1, float *x2, t_data *data)
{
	*x1 += data->shiftx;
	*y1 += data->shifty;
	*x2 += data->shiftx;
	data->y2 += data->shifty;
}

void	zoom_z(float *z1, float *z2, t_data *data)
{
	*z1 *= data->z_zoom;
	*z2 *= data->z_zoom;
}

void	destroy_and_set(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	set_image_and_connect_indexes(data);
	mlx_do_sync(data->mlx);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
