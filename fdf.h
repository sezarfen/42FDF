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

# define HEIGHT 800
# define WIDTH 1000

typedef struct	s_data {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx;
	void	*win;
	int		winx;
	int		winy;

	int		**map;
	int		mapw;
	int		maph;
	
	int		zoom;
	int		shiftx;
	int		shifty;
	int		color;
	double	angle;
}			t_data;

int		split_len(char **split);
void	free_split(char **split);
t_data	*read_map(char *file_name);
int		get_map_height(char *file_name);
int		get_map_width(char *file_name);
void	set_map(t_data *data, char *file_name, int i, int fd);
int 	max(int a, int b);
void	connect_indexes(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_image_and_connect_indexes(t_data *data);
void	isometric(float *x, float *y, float *z, t_data *data);
void	parallel(float *x, float *y, float *z, t_data *data);
void 	conic(float *x, float *y, float *z, t_data *data);
void	bresenham(float x1, float y1, float x2, float y2, t_data *data);

#endif