/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:18 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:45:28 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, float *z, t_data *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * cos(data->angle) - *z;
}

void	parallel(float *x, float *y, float *z, t_data *data)
{
	*x = *x + (*z * cos(data->angle));
	*y = *y + (*z * sin(data->angle));
}

void	set_projection(float *x, float *y, float *z, t_data *data)
{
	if (data->mode % 2 == 0)
		isometric(x, y, z, data);
	else
		parallel(x, y, z, data);
}
