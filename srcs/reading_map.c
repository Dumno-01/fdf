/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:14:41 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/09 16:23:13 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_heigth(char *file_name, t_data *data)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (0);
	data->heigth = 0;
	line = get_next_line(fd);
	data->width = count_word(line, ' ');
	while ((line))
	{
		data->heigth++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}

void	fill_z(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	read_map(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	data->z = malloc(sizeof(int *) * (data->heigth + 1));
	data->z[data->heigth] = NULL;
	while (i < data->heigth)
		data->z[++i] = malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error fd\n", 9), 0);
	i = 0;
	get_next_line(-1);
	line = get_next_line(fd);
	while (line)
	{
		fill_z(data->z[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
