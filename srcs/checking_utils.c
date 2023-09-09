/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:41:09 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/09 11:41:28 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max1(float a, float b)
{
	if (a > b)
		return (a);
	else
		return(b);
}

float   mod(float i)
{
	if (i >= 0)
		return(i);
	else
		return(-i);
}