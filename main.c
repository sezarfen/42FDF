/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:30:56 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:43:55 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_values(t_data *data)
{
	data->winx = 1920;
	data->winy = 1080;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winx, data->winy, "fdf");
	data->angle = 0.53;
	data->zoom = 10;
	data->color = 0;
	data->change_color = 1;
	data->shiftx = 400;
	data->shifty = 150;
	data->mode = 0;
	data->z_zoom = 1;
}

void	handle_key_nest(int keycode, t_data *data)
{
	if (keycode == 126)
		data->zoom += 3;
	if (keycode == 125)
		data->zoom -= 3;
	if (keycode == 0)
		data->shiftx -= 30;
	if (keycode == 2)
		data->shiftx += 30;
	if (keycode == 1)
		data->shifty += 30;
	if (keycode == 13)
		data->shifty -= 30;
}

int	handle_key(int keycode, t_data *data)
{
	handle_key_nest(keycode, data);
	if (keycode == 12)
		data->mode += 1;
	if (keycode == 15)
		data->z_zoom += 1.2;
	if (keycode == 14)
		data->z_zoom -= 1.2;
	if (keycode == 53)
	{
		free_all(data);
		exit(0);
	}
	destroy_and_set(data);
	return (0);
}

int	destroy(t_data *data)
{
	(void)data;
	free_all(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		check_up(av);
		data = read_map(av[1]);
		init_colors(data);
		init_values(data);
		set_info_page(data, av);
		set_image_and_connect_indexes(data);
		mlx_hook(data->win, 2, 1L, handle_key, data);
		mlx_hook(data->win, 17, 1L, destroy, data);
		mlx_loop(data->mlx);
	}
	ft_printf("Wrong number of arguments.\n");
	return (0);
}
