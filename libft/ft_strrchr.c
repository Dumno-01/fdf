/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:58 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 10:26:15 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*b;
	int		i;

	b = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (b[i] == (char)c)
			return (&b[i]);
		i--;
	}
	return (NULL);
}
