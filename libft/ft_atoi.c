/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:20:45 by ffreze            #+#    #+#             */
/*   Updated: 2023/06/22 15:35:38 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long int		nbr;
	int						sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
		if ((char)str[i++] == '-')
			sign ++;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
		nbr = nbr * 10 + ((char)str[i++] - '0');
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}
