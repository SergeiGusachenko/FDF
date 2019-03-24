/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:46 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/22 21:59:22 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_vector vec, int x, int y, int current_color)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	int end_color = 0xFF00FF;// will change this two fields
	int start_color =0xFFFFFF;

	if(vec.z == 0)
		return current_color;
	else if(vec.z == 2)
		return end_color;
	if (fabs(vec.x1 - vec.x0) > fabs(vec.y1 - vec.y0))
		percentage = percent(vec.x0, vec.x1, x);
	else
		percentage = percent(vec.y0, vec.y1,y);
	red = get_light((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, percentage);
	green = get_light((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, percentage);
	blue = get_light(start_color & 0xFF, end_color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	to_iso(double *x, double *y, double z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.423599);
}

void	print_line(t_vector vector, t_fdf *fdf)
{
	t_vector vec = vector;
	int color;
	int x1 = fdf->window_width + vector.x1 * fdf->image_size;
	int x0 =fdf->window_width+ vector.x0 * fdf->image_size;
	int y1 =fdf->window_hieght + vector.y1 * fdf->image_size;
	int y0 =fdf->window_hieght + vector.y0 * fdf->image_size;
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;
	color = 0xFFFFFF;
	while(1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0,color);
		color = get_color(vec, x0/(fdf->image_size * 250), y0/(fdf->image_size * 250), color);
		if (x0==x1 && y0==y1)
		break;
			e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
		}
}

int		main(int argc, char **argv)
{
	int				fd;
	t_fdf			*fdf;

	if (argc == 2)
	{
		fdf = malloc(sizeof(t_fdf));
		fdf->image_size = 30;
		fdf->window_hieght = 500;
		fdf->window_width = 500;
		fd = open(argv[1], O_RDWR);
		fdf->mlx = mlx_init(); // returns a void*, it's just a connection login to the graphical server.
		fdf->win= mlx_new_window(fdf->mlx , HIEGHT, WIDTH, "mlx 42");
		read_map(fd,fdf);
		mlx_key_hook(fdf->win, key_press, fdf);
		mlx_hook(fdf->win, 4, 0, hook_mouse, fdf);
	 	drawing(fdf->map, fdf->map_width, fdf->map_hieght, fdf);
		mlx_loop(fdf->mlx);
	 }
	else
		ft_putstr("usage: ./fdf [map]\n");
	return (0);
	}
