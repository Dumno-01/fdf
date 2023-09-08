/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:15:01 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/08 11:30:11 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct
{
    int width;
    int heigth;
    int **z;
    int zoom;
    int color;
    int shift_x;
    int shift_y;

    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;

#endif

void    read_map(char *file_name, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
void    print(fdf *data);
void    shifting_fdf(float *x, float *y, float *x1, float *y1, fdf *data);
void    setting_fdf(float *x, float *y, float *x1, float *y1, fdf *data);
void    step_set(float *x, float *y, float *x1, float *y1, fdf *data);