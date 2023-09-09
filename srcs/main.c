/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:13:54 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/09 16:22:57 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_data *data)
{
	if (key == 65307)
		close_window(data);
	if (key == 65362)
		data->shift_y -= 10;
	if (key == 65364)
		data->shift_y += 10;
	if (key == 65361)
		data->shift_x -= 10;
	if (key == 65363)
		data->shift_x += 10;
	if (key == 65451)
		data->zoom += 10;
	if (key == 65453)
		data->zoom -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print(data);
	return (0);
}

int	data_set(char *file_name, t_data *data)
{
	if (get_heigth(file_name, data) == 0)
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		close_window(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	if (!data->win_ptr)
		close_window(data);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->bg.img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	if (!data->img.img_ptr || !data->bg.img_ptr)
		close_window(data);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, \
		&data->img.len, &data->img.end);
	data->img.bpp /= 8;
	data->bg.addr = mlx_get_data_addr(data->bg.img_ptr, &data->bg.bpp, \
		&data->bg.len, &data->bg.end);
	data->bg.bpp /= 8;
	data->zoom = 20;
	return (1);
}

int	close_window(t_data *data)
{
	int	y;

	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->bg.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bg.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	y = 0;
	while (y <= data->heigth)
		free(data->z[y++]);
	free(data->z);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	check_ext(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	i--;
	if (file_name[i] == 'f' && file_name[i - 1] == 'd' && \
		file_name[i - 2] == 'f' && file_name[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (argc == 2 && check_ext(argv[1]) == 1)
	{
		data = malloc(sizeof(t_data));
		ft_bzero(data, sizeof(t_data));
		if (!data)
			exit(EXIT_FAILURE);
		if (data_set(argv[1], data) == 0 || read_map(argv[1], data) == 0)
			return (free(data), write(2, "Map error\n", 10));
		print(data);
		mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
		mlx_hook(data->win_ptr, 17, 0L, close_window, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		write(2, "Select a single map file (.fdf)\n", 32);
}
