/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 00:08:23 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/27 21:52:32 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				print_line(t_vector vector, t_fdf *fdf)
{
	t_coords	cds;
	int			err;
	int			e2;

	cds = fill_cds(vector, fdf);
	err = (cds.dx > cds.dy ? cds.dx : -cds.dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, cds.x0, cds.y0, vector.end_color);
		vector.end_color =
		get_color(to_disp(vector, fdf), cds.x0, cds.y0, vector.end_color);
		if (cds.x0 == cds.x1 && cds.y0 == cds.y1)
			break ;
		e2 = err;
		if (e2 > -cds.dx)
		{
			err -= cds.dy;
			cds.x0 += cds.sx;
		}
		if (e2 < cds.dy)
		{
			err += cds.dx;
			cds.y0 += cds.sy;
		}
	}
}

void				send_to_print(t_vector vec, t_fdf *fdf)
{
	vec.z0 = fdf->map[(int)vec.y0][(int)vec.x0];
	vec.z1 = fdf->map[(int)vec.y1][(int)vec.x1];
	vec.window_width = fdf->window_width;
	vec.image_size = fdf->image_size;
	vec.end_color = fdf->end_color;
	vec.start_color = fdf->start_color;
	to_iso(&(vec.x0), &(vec.y0),
	fdf->map[(int)vec.y0][(int)vec.x0], fdf);
	to_iso(&(vec.x1), &(vec.y1), fdf->map[(int)vec.y1][(int)vec.x1], fdf);
	print_line(vec, fdf);
}

t_vector			fill_vec(int x0, int y0, int x1, int y1)
{
	t_vector vector;

	vector.x0 = x0;
	vector.y0 = y0;
	vector.x1 = x1;
	vector.y1 = y1;
	return (vector);
}

void				vector(int y, int x, t_fdf *fdf)
{
	fdf->c_angle = 0.523599;
	fdf->s_angle = 0.423599;
	if (x + 1 < fdf->map_width)
		send_to_print(fill_vec(x, y, x + 1, y), fdf);
	if (y + 1 < fdf->map_hieght)
		send_to_print(fill_vec(x, y, x, y + 1), fdf);
}

void				drawing(int width, int hieght, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < hieght)
	{
		j = 0;
		while (j < width)
		{
			vector(i, j, fdf);
			j++;
		}
		i++;
	}
}
