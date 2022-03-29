/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:46:19 by tmillenn          #+#    #+#             */
/*   Updated: 2021/04/23 16:05:27 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(unsigned int u_n, int fd)
{
	if (u_n >= 10)
	{
		ft_write(u_n / 10, fd);
		ft_putchar_fd(u_n % 10 + '0', fd);
	}
	if (u_n < 10)
		ft_putchar_fd(u_n + '0', fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		u_n = n * (-1);
	}
	else
		u_n = n;
	ft_write(u_n, fd);
}
