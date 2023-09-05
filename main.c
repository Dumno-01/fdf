/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:13:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/05 07:19:14 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key

int main(int argc, char **argv)
{
    fdf *data;

    data = malloc(sizeof(fdf));
    read_file(argc[1], data);

    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    data->zoom = 20;

    bresenham(10, 10, 600, 300, data);
    print(data);
    mlx_key_hook(data->win_ptr, deal_key, NULL);
    mlx_loop(data->mlx_ptr);
}