/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:45:24 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 16:33:07 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = 0;
	while (b[i] && b[i] != (char)c)
		i++;
	if (b[i] == (char)c)
		return (&b[i]);
	return (NULL);
}
