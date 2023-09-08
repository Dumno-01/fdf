/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 06:38:23 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/08 11:46:14 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    z = data->z[(int)y][(int)x] * 2;
    z1 = data->z[(int)y1][(int)x1] * 2;
    
    setting_fdf(&x, &y, &x1, &y1, data);

    data->color = (z || z1) ? 0xe80c0c : 0xffffff;

    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    shifting_fdf(&x, &y, &x1, &y1, data);
    step_set(&x, &y, &x1, &y1, data);
}

void    print(fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->heigth)
    {
        x = 0;
        while (x < data->width)
        {
            if(x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if(y < data->heigth - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}