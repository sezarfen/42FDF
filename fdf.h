#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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

	int		**map;
	int		mapw;
	int		maph;
	
	int		starter;
	int		len_x;
	int		len_y;
}			t_data;

int		split_len(char **split);
void	free_split(char **split);
t_data	*read_map(char *file_name);
int		get_map_height(char *file_name);
int		get_map_width(char *file_name);
void	set_indexes(int *map_line, char *newline);
void	set_map(t_data *data, char *file_name, int i, int fd);
int 	max(int a, int b);
void	connect_indexes(t_data *data);

#endif