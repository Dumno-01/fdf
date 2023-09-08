/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:13:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/08 12:01:58 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int     deal_key(int key, fdf *data)
{
    if(key == 65362)
        data->shift_y -= 10;
    if(key == 65364)
        data->shift_y += 10;
    if(key == 65361)
        data->shift_x -= 10;
    if(key == 65363)
        data->shift_x += 10;
    if(key == 65451)
        data->zoom += 10;
    if(key == 65453)
        data->zoom -= 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    print(data);
    return(0);
}

int main(int argc, char **argv)
{

    (void)argc;
    
    fdf *data;

    if (argc == 2)
    {
		data = malloc(sizeof(fdf));
		read_map(argv[1], data);

		int j = 0;
		int i = 0;
		while(j != data->heigth)
     	{
			i = 0;
			while(i != data->width)
        	{
				printf("%d", data->z[j][i]);
			i++;
			}
			j++; 
		}    
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		data->zoom = 20;

		print(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
    }
	else
	write(1, "Select a single map file (.fdf)\n", 32);
}