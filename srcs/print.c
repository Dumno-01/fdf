/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 06:38:23 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/09 13:46:33 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_data *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    x_step = 0;
    y_step = 0;
    max = 0;
    z = data->z[(int)y][(int)x] * 2;
    z1 = data->z[(int)y1][(int)x1] * 2;
    
    setting_fdf(&x, &y, &x1, &y1, data);

    if(z || z1)
        data->color = 0xe80c0c;
    else
        data->color = 0xffffff;

    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    shifting_fdf(&x, &y, &x1, &y1, data);
    step_set(&x, &y, &x1, &y1, data);
}

void    draw_bg(t_img *img, int color)
{
    int x;
    int y;
    int *dst;

    y = 0;
    dst = (int *)img->addr;
    while (y < 1000)
    {
        x = 0;
        while (x < 1000)
        {
            dst[y * 1000 + x] = color;
            x++;
        }
        y++;
    }
}

void    print(t_data *data)
{
    t_pos pos;

    pos.y = 0;
    draw_bg(&data->img, 0xFF0A0A0A);
    while (pos.y < data->heigth)
    {
        pos.x = 0;
        while (pos.x < data->width)
        {
            if(pos.x < data->width - 1)
                bresenham(pos.x, pos.y, pos.x + 1, pos.y, data);
            if(pos.y < data->heigth - 1)
                bresenham(pos.x, pos.y, pos.x, pos.y + 1, data);
            pos.x++;
        }
        pos.y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
        data->bg.img_ptr, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
        data->img.img_ptr, 0, 0);
}