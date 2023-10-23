/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:52:36 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/07 10:10:01 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_len(long c)
{
	int	i;

	i = 0;
	while (c / 10 != 0)
	{
		c /= 10;
		i++;
	}
	i++;
	return (i);
}

int	fill(char *itoa, long a, int len)
{
	while (a != 0)
	{
		itoa[len--] = (a % 10) + 48;
		a /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	a;
	char	*itoa;
	int		len;

	a = n;
	len = 0;
	if (a < 0)
	{
		a = -a;
		len++;
	}
	len += nb_len(a);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len--] = '\0';
	if (a == 0)
	{
		itoa[len] = '0';
		return (itoa);
	}
	len = fill(itoa, a, len);
	if (len == 0)
		itoa[len] = '-';
	return (itoa);
}
