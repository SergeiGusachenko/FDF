/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:46 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/21 13:20:34 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	int x1 =	fdf->window_width + vector.x1 * fdf->image_size;
	int x0 =	fdf->window_width+ vector.x0 * fdf->image_size;
	int y1 =	fdf->window_hieght + vector.y1 * fdf->image_size;
	int y0 =	fdf->window_hieght + vector.y0 * fdf->image_size;
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while(1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0xFFFFFF);
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
	t_fdf		*fdf;

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
