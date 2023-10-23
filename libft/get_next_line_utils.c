/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:10:40 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/15 09:10:41 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *bigline)
{
	int	i;

	i = 0;
	while (bigline[i])
	{
		if (bigline[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
