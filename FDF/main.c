/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:46 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/28 11:48:43 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			return_light(int start_color, int end_color, double percentage)
{
	int red;
	int green;
	int blue;

	red = get_light((start_color >> 16) & 0xFF,
	(end_color >> 16) & 0xFF, percentage);
	green = get_light((start_color >> 8) & 0xFF,
	(end_color >> 8) & 0xFF, percentage);
	blue = get_light(start_color & 0xFF, end_color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			get_color(t_vector vec, int x, int y, int current_color)
{
	double	percentage;
	int		end_color;
	int		start_color;

	start_color = START_COLOR;
	end_color = END_COLOR;
	if (vec.z0 == vec.z1 && vec.z1 == 0)
		return (vec.start_color);
	else if (vec.z0 == vec.z1)
		return (vec.end_color);
	if (fabs(vec.x1 - vec.x0) > fabs(vec.y1 - vec.y0))
		percentage = percent(vec.x0, vec.x1, x);
	else
		percentage = percent(vec.y0, vec.y1, y);
	if (vec.z1 > vec.z0)
	{
		current_color = end_color;
		end_color = start_color;
		start_color = current_color;
	}
	return (return_light(start_color, end_color, percentage));
}

void		to_iso(double *x, double *y, double z, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(fdf->c_angle);
	*y = -z * fdf->z_height + (previous_x + previous_y) * sin(fdf->s_angle);
}

int			main(int argc, char **argv)
{
	int				fd;
	t_fdf			*fdf;

	if (argc == 2)
	{
		fdf = malloc(sizeof(t_fdf));
		fdf->image_size = 30;
		fdf->window_hieght = 500;
		fdf->window_width = 500;
		fdf->z_height = 1;
		fd = open(argv[1], O_RDWR);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, HIEGHT, WIDTH, "mlx 42");
		fdf->end_color = END_COLOR;
		fdf->start_color = START_COLOR;
		read_map(fd, fdf);
		mlx_key_hook(fdf->win, key_press, fdf);
		mlx_hook(fdf->win, 4, 0, hook_mouse, fdf);
		drawing(fdf->map_width, fdf->map_hieght, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_putstr("usage: ./fdf [map]\n");
	return (0);
}
