/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:57:00 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/07 09:54:56 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hy, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!hy && !len)
		return (0);
	if (n[0] == '\0' || hy == n)
		return ((char *)hy);
	i = 0;
	while (hy[i])
	{
		j = 0;
		while (hy[i + j] == n[j] && (i + j) < len)
		{
			if (hy[i + j] == '\0' && n[j] == '\0')
				return ((char *)&hy[i]);
			j++;
		}
		if (n[j] == '\0')
			return ((char *)(hy + i));
		i++;
	}
	return (0);
}
