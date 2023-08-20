#include "fdf.h"

void	set_map(t_data *data, char *file_name)
{
	char	*newline;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY); // read_map kısmında dosyanın açılıp açılmadığını zaten kontrol ettik
	if (fd < 0)
	{
		//	free_all();
		exit(1);
	}
	newline = get_next_line(fd);
	if (!newline)
		//free_all();
		exit(1);
	i = 0;
	while (newline)
	{
		set_indexes(data->map[i++], newline);
		free(newline);
		newline = get_next_line(fd);
	}
}

void	set_indexes(int *map_line, char *newline)
{
	char	**split;
	int		slen;
	int		i;

	split = ft_split(newline, ' ');
	i = 0;
	while (split[i])
	{
		map_line[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
}