/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:36:41 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 17:40:53 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx_macos/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;
	int		**map;
	int		**colors;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		winx;
	int		winy;
	int		mapw;
	int		maph;
	float	y2;
	int		zoom;
	int		shiftx;
	int		shifty;
	int		color;
	int		change_color;
	double	angle;
	int		mode;
	int		z_zoom;
}			t_data;

int		split_len(char **split);
void	free_split(char **split);
t_data	*read_map(char *file_name);
int		get_map_height(char *file_name);
int		get_map_width(char *file_name);
void	set_map(t_data *data, int i, int fd);
int		max(int a, int b);
void	connect_indexes(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_image_and_connect_indexes(t_data *data);
void	isometric(float *x, float *y, float *z, t_data *data);
void	parallel(float *x, float *y, float *z, t_data *data);
void	bresenham(float x1, float y1, float x2, t_data *data);
int		get_max_z(t_data *data);
int		get_min_z(t_data *data);
void	init_colors(t_data *data);
int		set_color(float z, t_data *data);
void	check_up(char **av);
void	zoom(float *x1, float *y1, float *x2, t_data *data);
void	set_indexes(float *x1, float *y1, float *x2, t_data *data);
void	zoom_z(float *z1, float *z2, t_data *data);
void	set_info_page(t_data *data, char **av);
void	set_projection(float *x, float *y, float *z, t_data *data);
void	free_all(t_data *data);
void	destroy_and_set(t_data *data);

#endif