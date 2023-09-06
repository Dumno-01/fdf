/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:20:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 10:25:26 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	t_src;
	size_t	t_dest;

	i = 0;
	t_dest = ft_strlen(dest);
	t_src = ft_strlen(src);
	if (size == 0)
		return (t_src);
	while (src[i] != '\0' && t_dest + i < size - 1)
	{
		dest[t_dest + i] = src[i];
		i++;
	}
	dest[t_dest + i] = '\0';
	if (size < t_dest)
		return (t_src + size);
	return (t_dest + t_src);
}
