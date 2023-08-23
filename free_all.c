/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:10 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 17:17:43 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->maph)
		free(data->map[i++]);
	free(data->map);
}

void	free_colors(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->maph)
		free(data->colors[i++]);
	free(data->colors);
}

void	free_all(t_data *data)
{
	free(data->img);
	free(data->addr);
	free_map(data);
	free_colors(data);
	free(data);
}
