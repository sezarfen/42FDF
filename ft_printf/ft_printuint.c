/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:45:35 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/09 08:45:36 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_reverse(unsigned int u)
{
	if (u == 0)
		return (1);
	else
	{
		if (print_reverse(u / 10) == 1)
		{
			ft_putchar((u % 10) + 48);
			return (1);
		}
	}
	return (0);
}

static int	unslen(unsigned int u)
{
	int	i;

	i = 0;
	while (u != 0)
	{
		i++;
		u /= 10;
	}
	return (i);
}

int	ft_printuint(unsigned int u)
{
	int	len;

	len = 0;
	if (u == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_reverse(u);
	len += unslen(u);
	return (len);
}
