/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresham_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:32:42 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/08 17:06:45 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)
float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    setting_fdf(float *x, float *y, float *x1, float *y1, t_data *data)
{
    *x *= (float)data->zoom;
    *y *= (float)data->zoom;
    *x1 *= (float)data->zoom;
    *y1 *= (float)data->zoom;
}

void    shifting_fdf(float *x, float *y, float *x1, float *y1, t_data *data)
{
    *x += (float)data->shift_x;
    *y += (float)data->shift_y;
    *x1 += (float)data->shift_x;
    *y1 += (float)data->shift_y;
}

void    ft_pixel_put(t_data *data, int x, int y, int color)
{
    int *dst;

    if (x >= 0 && x < 1000 && y > 0 && y < 1000)
    {
        dst = (int *)data->img.addr;
        dst[y * 1000 + x] = color;
    }
}

void    step_set(float *x, float *y, float *x1, float *y1, t_data *data)
{
    float x_step;
    float y_step;
    int max;
    
    x_step = *x1 - *x;
    y_step = *y1 - *y;
    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;

    while ((int)(*x - *x1) || (int)(*y - *y1))
    {
        ft_pixel_put(data, *x, *y, data->color);
        //mlx_pixel_put(data->mlx_ptr, data->win_ptr, *x, *y, data->color);
        *x += x_step;
        *y += y_step;
    }
}