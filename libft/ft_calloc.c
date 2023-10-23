/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:49:08 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/07 10:43:24 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*area;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	area = malloc(count * size);
	if (!area)
		return (NULL);
	ft_bzero(area, count * size);
	return (area);
}
