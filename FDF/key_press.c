/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:10:44 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/28 11:52:37 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		hook_mouse(int button, t_fdf *fdf)
{
	if (button == SCROLL_UP)
	{
		if (fdf->image_size < 1000)
		{
			fdf->image_size++;
			mlx_clear_window(fdf->mlx, fdf->win);
			drawing(fdf->map_width, fdf->map_hieght, fdf);
		}
	}
	if (button == SCROLL_DOWN)
	{
		if (fdf->image_size > 0)
		{
			fdf->image_size--;
			mlx_clear_window(fdf->mlx, fdf->win);
			drawing(fdf->map_width, fdf->map_hieght, fdf);
		}
	}
	return (0);
}

int		key_press(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (key == ESC)
		exit(0);
	if (key == MOVE_RIGHT)
		fdf->window_width = fdf->window_width + 3;
	if (key == MOVE_LEFT)
		fdf->window_width = fdf->window_width - 3;
	if (key == MOVE_UP)
		fdf->window_hieght = fdf->window_hieght - 3;
	if (key == MOVE_DOWN)
		fdf->window_hieght = fdf->window_hieght + 3;
	if (key == CHANGE_COLOR)
		fdf->end_color = fdf->end_color >> 1;
	if (fdf->end_color == 0)
		fdf->end_color = END_COLOR;
	if (fdf->start_color == 0)
		fdf->start_color = START_COLOR;
	if (key == CHANGE_START_COLOR)
		fdf->start_color = fdf->start_color >> 1;
	if (key == HIEGHT_UP)
		fdf->z_height += 0.1;
	if (key == HIEGHT_DOWN)
		fdf->z_height -= 0.1;
	drawing(fdf->map_width, fdf->map_hieght, fdf);
	return (0);
}
