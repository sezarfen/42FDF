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

	int		**map;
	int		mapw;
	int		maph;
}			t_data;

int		split_len(char **split);
void	free_split(char **split);
t_data	*read_map(char *file_name);
int		get_map_height(char *file_name);
int		get_map_width(char *file_name);
void	set_indexes(int *map_line, char *newline);
void	set_map(t_data *data, char *file_name, int i, int fd);

#endif