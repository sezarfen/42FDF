/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:55:14 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/06 09:14:19 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_number(long a, int fd)
{
	if (a == 0)
		return (1);
	else
	{
		if (print_number(a / 10, fd) == 1)
		{
			ft_putchar_fd((a % 10) + 48, fd);
			return (1);
		}
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a == 0)
		ft_putchar_fd('0', fd);
	print_number(a, fd);
}
