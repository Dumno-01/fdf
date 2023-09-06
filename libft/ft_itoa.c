/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:43:21 by ffreze            #+#    #+#             */
/*   Updated: 2022/11/18 14:30:30 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(int n, char *str, size_t size)
{
	long int	nb;

	nb = n;
	size = size - 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[size] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	if (nb >= 0)
		str[size] = nb + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		size;
	long int	temp;

	size = 1;
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		size++;
	}
	while (temp > 9)
	{
		temp /= 10;
		size++;
	}
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	res = ft_putnbr(n, res, size);
	return (res);
}
