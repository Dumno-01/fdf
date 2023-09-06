/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:13:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 14:32:51 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int     deal_key(int key, fdf *data)
{
    printf("%d\n", key);
    if(key == 65364)
        data->shift_y -= 10;
    if(key == 65362)
        data->shift_y += 10;
    if(key == 65361)
        data->shift_x -= 10;
    if(key == 65363)
        data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data);
    print(data);
    return(0);
}

int main(int argc, char **argv)
{

    (void)argc;
    
    fdf *data;

    data = malloc(sizeof(fdf));
    read_map(argv[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    data->zoom = 20;

    // bresenham(10, 10, 600, 300, data);
    print(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
}