/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:41:21 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 10:28:18 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*smod;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start])
	{
		if (is_set(s1[start], set) == 1)
			start++;
		else
			break ;
	}
	while (end > start)
	{
		if (is_set(s1[end - 1], set) == 1)
			end--;
		else
			break ;
	}
	smod = ft_substr(s1, start, end - start);
	return (smod);
}
