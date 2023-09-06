/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:18:03 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 10:26:54 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in(char *sr, char *pr, int idx)
{
	size_t	i;

	i = 0;
	while (pr[i] != '\0' && sr[idx + i] != '\0')
	{
		if (pr[i] != sr[idx + i])
			return (0);
		i++;
	}
	if (sr[idx + i] == '\0' && pr[i] != '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 && !str)
		return (0);
	if ((char)to_find[i] == '\0')
		return ((char *)str);
	while ((char)str[i] != '\0' && i < n)
	{
		if (n - i < (size_t)ft_strlen(to_find))
			return (0);
		if (is_in((char *)str, (char *)to_find, i))
			return ((char *)str + i);
		i++;
	}
	return (0);
}
