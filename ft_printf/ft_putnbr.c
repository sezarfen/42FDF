/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:46:03 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/09 08:46:04 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_reverse(long a)
{
	if (a == 0)
		return (1);
	else
	{
		if (print_reverse(a / 10) == 1)
		{
			ft_putchar((a % 10) + 48);
			return (1);
		}
	}
	return (0);
}

static int	number_len(long a)
{
	int	i;

	i = 0;
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long	a;
	int		len;

	a = nb;
	len = 0;
	if (a < 0)
	{
		len += write(1, "-", 1);
		a = -a;
	}
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += number_len(a);
	print_reverse(a);
	return (len);
}
