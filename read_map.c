/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:02 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:45:59 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*read_map(char *file_name)
{
	t_data	*data;
	int		fd;
	int		i;

	data = malloc(sizeof(t_data));
	data->mapw = get_map_width(file_name);
	data->maph = get_map_height(file_name);
	data->map = malloc(sizeof(int *) * data->maph);
	i = 0;
	while (i < data->maph)
		data->map[i++] = malloc(sizeof(int) * data->mapw);
	i = 0;
	fd = open(file_name, O_RDONLY);
	set_map(data, 0, fd);
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

void	set_map(t_data *data, int i, int fd)
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
