/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:56:40 by ffreze            #+#    #+#             */
/*   Updated: 2022/11/17 14:11:41 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long int	ft_neg(long int nb, int fd)
{
	nb *= -1;
	write(fd, "-", 1);
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	mod;
	long int	nb;

	nb = n;
	if (nb < 0)
		nb = ft_neg(nb, fd);
	if (nb > 9)
	{
		mod = nb % 10 + 48;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &mod, 1);
	}
	else
	{
		nb = nb + 48;
		write (fd, &nb, 1);
	}
}
