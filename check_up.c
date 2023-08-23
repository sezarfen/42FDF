/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:04 by fdundar           #+#    #+#             */
/*   Updated: 2023/08/23 16:33:47 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_more(int fd, int slen)
{
	char	*newline;
	char	**split;
	int		temp_len;

	newline = get_next_line(fd);
	while (newline)
	{
		split = ft_split(newline, ' ');
		temp_len = split_len(split);
		if (temp_len != slen)
		{
			ft_printf("Invalid map, please use same line length.\n");
			free(newline);
			free_split(split);
			exit(1);
		}
		free_split(split); 
		free(newline);
		newline = get_next_line(fd);
	}
	close(fd);
}

void	check_lines(char **av)
{
	int		fd;
	char	*newline;
	char	**split;
	int		slen;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Wrong file name\n");
		exit(1);
	}
	newline = get_next_line(fd);
	if (!newline)
		exit(1);
	split = ft_split(newline, ' ');
	slen = split_len(split);
	free_split(split);
	free(newline);
	check_more(fd, slen);
}

void	check_up(char **av)
{
	char	*str;
	int		i;

	str = ft_strnstr(av[1], ".fdf", ft_strlen(av[1]));
	i = ft_strlen(av[1]) - ft_strlen(str) - 1;
	if (i < 0 || av[1][i] == '/')
	{
		ft_printf("ghost file, are you Casper?\n");
		exit(1);
	}
	if (!str || ft_strlen(str) != 4)
	{
		ft_printf("Wrong file format, should be and with ..[.fdf]\n");
		exit(1);
	}
	check_lines(av);
}
