#include "fdf.h"
/*
0 0 0 0 0  0  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 | Height -> data->maph
0 0 0 0 0  0  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 | 
0 0 0 0 0 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 | 
0 0 0 0 0 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 | 
0 0 0 0 0 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
0 0 0 0 0 10  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
0 0 0 0 0 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
0 0 0 0 0 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
0 0 0 0 0  0 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
- - - - - - - - - - - - - - - - - - - - - 
			Weight = data->mapw
// extract 1 newline
// ft_split(newline, ' ');
// -> "0", "0", "0" ... <- we need to check split_len
*/

// İşlemleri dosya varmış gibi yapalım, dosyanın açılıp açılmadığına sonra bakarız
// ve düzgün bir şekilde okunabilir mi?
t_data *read_map(char *file_name)
{
	t_data *data;
	int		fd;
	int		i;

	data = malloc(sizeof(t_data));
	data->mapw = get_map_width(file_name);
	data->maph = get_map_height(file_name);
	ft_printf("current maph :%d\n", data->maph);
	data->map = malloc(sizeof(int *) * data->maph);
	i = 0;
	while (i < data->maph)
		data->map[i++] = malloc(sizeof(int) * data->mapw);
	i = 0;
	fd = open(file_name, O_RDONLY);
	set_map(data, file_name, 0, fd);
	close(fd);
	return (data); 
}

int	get_map_width(char *file_name)
{
	char	**split;
	char	*newline;
	int		len;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	newline = get_next_line(fd);
	split = ft_split(newline, ' ');
	len = split_len(split);
	free_split(split);
	free(newline);
	close(fd);
	return (len);
}

int	get_map_height(char *file_name)
{
	char	*newline;
	int		len;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	len = 0;
	newline = get_next_line(fd);
	while (newline)
	{
		free(newline);
		len++;
		newline = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	set_map(t_data *data, char *file_name, int i, int fd)
{
	char	*newline;
	char	**split;
	int		j;

	if (fd < 0)
		exit(1);
	newline = get_next_line(fd);
	if (!newline)
		exit(1);
	j = 0;
	while (newline)
	{
		split = ft_split(newline, ' ');
		while (split[j])
		{
			data->map[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
		j = 0;
		free_split(split);
		free(newline);
		newline = get_next_line(fd);
	}
}
