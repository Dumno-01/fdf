/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:15:01 by ffreze            #+#    #+#             */
/*   Updated: 2023/09/09 14:30:34 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_data
{
	int		width;
	int		heigth;
	int		**z;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	x;
	float	y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	bg;
}	t_data;

int		read_map(char *file_name, t_data *data);
void	bresenham(t_pos pos, float x1, float y1, t_data *data);
void	print(t_data *data);
void	shifting_fdf(t_pos *pos, float *x1, float *y1, t_data *data);
void	setting_fdf(t_pos *pos, float *x1, float *y1, t_data *data);
void	step_set(t_pos *pos, float *x1, float *y1, t_data *data);
int		close_window(t_data *data);
int		get_heigth(char *file_name, t_data *data);
int		get_width(char *file_name);
float	max1(float a, float b);
float	mod(float i);
#endif