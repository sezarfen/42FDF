/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:45:28 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/09 08:45:28 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned int u, char *hex)
{
	if (u < 16)
	{
		ft_putchar(hex[u % 16]);
	}
	else
	{
		print_hex(u / 16, hex);
		ft_putchar(hex[u % 16]);
	}
}

static int	hexlen(unsigned int u)
{
	int	i;

	i = 0;
	while (u != 0)
	{
		i++;
		u /= 16;
	}
	return (i);
}

int	ft_puthex(unsigned int u, char *hex)
{
	int	len;

	len = 0;
	if (u == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += hexlen(u);
	print_hex(u, hex);
	return (len);
}
