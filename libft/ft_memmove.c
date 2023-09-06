/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:57 by ffreze            #+#    #+#             */
/*   Updated: 2022/11/10 19:00:23 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*s;
	size_t			i;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	if (d > s)
	{
		while (size != 0)
		{
			size--;
			d[size] = s[size];
		}
		return (dest);
	}
	else if (s > d)
	{
		while (size != i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
