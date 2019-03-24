/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 00:08:23 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/22 21:05:33 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(int **map, t_fdf *fdf)
{
	int i = 0;
	int j = 0;
	while(i < fdf->map_hieght)
	{
		while(j< fdf->map_width)
		{
			ft_putnbr(map[i][j]);
			ft_putchar(' ');
			j++;
		}
	j = 0;
	i++;
	ft_putchar('\n');
	}
}

void	send_to_print(t_vector vector, t_fdf *fdf)
{
	if(fdf->map[(int)vector.y0][(int)vector.x0] == fdf->map[(int)vector.y1][(int)vector.x1])
	{
		if (fdf->map[(int)vector.y0][(int)vector.x0] == 0)
			vector.z = 0;
		else
			vector.z = 2;
	}
	else
		vector.z = 1;
	vector.window_width = fdf->window_width;
	vector.image_size = fdf->image_size;
	to_iso(&(vector.x0),&(vector.y0),fdf->map[(int)vector.y0][(int)vector.x0]);
	to_iso(&(vector.x1), &(vector.y1),fdf->map[(int)vector.y1][(int)vector.x1]);
	print_line(vector, fdf);
}

t_vector	fill_vec(x0, y0, x1, y1)
{
	t_vector vector;

	vector.x0 = x0;
	vector.y0 = y0;
	vector.x1  = x1;
	vector.y1 = y1;
	return vector;
}

void	vector(double **map, int y, int x , t_fdf *fdf)
{
	if(x + 1 < fdf->map_width)
		send_to_print(fill_vec(x,y,x + 1, y), fdf);
	if(y + 1 < fdf->map_hieght)
		send_to_print(fill_vec(x,y,x, y + 1), fdf);
}

void	drawing(double** map, int width, int hieght, t_fdf *fdf)
{
	int i;
	int j;
	i = 0;

	while(i < hieght)
	{
		j = 0;
		while(j < width)
		{
		vector(map, i, j, fdf);
			j++;
		}
		i++;
	}
}
