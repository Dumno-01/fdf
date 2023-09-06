/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:14:41 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/06 16:51:41 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     get_heigth(char *file_name)
{
    char	*line;
    int		fd;
    int		heigth;

    line = NULL;
    fd = open(file_name, O_RDONLY, 0);
    heigth = 0;
    while((line = get_next_line(fd)))
    {
        heigth++;
        free(line);
    }
    close(fd);
    return(heigth);
}

int     get_width(char *file_name)
{
    int		width;
    int		fd;
    char	*line;

    width = 0;
    line = NULL;
    fd = open(file_name, O_RDONLY, 0);
    line = get_next_line(fd);
    width = count_word(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    fill_z(int *z_line, char *line)
{
    char **nums;
    int i;
    
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

void    read_map(char *file_name, fdf *data)
{
    int     fd;
    char     *line;
    int i;
    
    line = NULL;
    data->heigth = get_heigth(file_name);
	printf("data->heigth %d\n", data->heigth);
    data->width = get_width(file_name);
	printf("data->width %d\n", data->width);

    i = 0;
    data->z = malloc(sizeof(int*) * (data->heigth + 1));
    while (i <= data->heigth)
        data->z[i++] = malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY);
    i = 0;
    line = get_next_line(fd);
	// printf("fd %d line\t%s\n", fd, line);
    while (line)
    {
        // fill_z(data->z[i], line);
        printf("line %s\n", line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    printf("oui\n");
    close(fd);
    data->z[i] = NULL;
}