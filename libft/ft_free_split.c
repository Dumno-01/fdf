/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:46:28 by ffreze            #+#    #+#             */
/*   Updated: 2023/06/22 14:01:53 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(void *splitted_element)
{
	size_t	i;

	if (splitted_element == NULL)
		return ;
	i = 0;
	while (((char **)splitted_element)[i])
		free(((char **)splitted_element)[i++]);
	free(splitted_element);
}
