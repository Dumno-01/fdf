/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:46:52 by ffreze            #+#    #+#             */
/*   Updated: 2022/11/10 18:49:39 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	size_t			k;

	k = 0;
	i = (unsigned char *) src;
	j = (unsigned char *) dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n != k)
	{
		j[k] = i[k];
		k++;
	}
	return (dest);
}
