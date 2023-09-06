/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:38:04 by ffreze            #+#    #+#             */
/*   Updated: 2022/11/17 16:07:59 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int found, size_t size)
{
	size_t		k;
	const char	*temp;

	temp = (const char *)s;
	k = 0;
	while (k < size)
	{
		if (*(temp + k) == (char)found)
			return ((void *)temp + k);
		k++;
	}
	return (NULL);
}
