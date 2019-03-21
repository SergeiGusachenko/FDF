/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:10:44 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/21 01:31:44 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		hook_mouse(int button, int x, int y, t_fdf *fdf)
{
	if(button == SCROLL_UP)
	{
		if(fdf->image_size < 1000)
		{
			fdf->image_size++;
			mlx_clear_window(fdf->mlx,fdf->win);
	 		drawing(fdf->map, fdf->map_width, fdf->map_hieght, fdf);
		}
	}
		if(button == SCROLL_DOWN)
	{
		if(fdf-> image_size > 0)
		{
			fdf->image_size--;
			mlx_clear_window(fdf->mlx,fdf->win);
	 		drawing(fdf->map, fdf->map_width, fdf->map_hieght, fdf);
		}
	}
	return 0;
}

int		key_press(int key,t_fdf  *fdf)
{
	mlx_clear_window(fdf->mlx,fdf->win);
	if(key == ESC)
		exit(0);
	if(key == MOVE_RIGHT )
		fdf->window_width = fdf->window_width + 3;
	if(key == MOVE_LEFT)
		fdf->window_width = fdf->window_width - 3;
	if(key == MOVE_UP)
		fdf->window_hieght = fdf->window_hieght - 3;
	if(key == MOVE_DOWN)
		fdf->window_hieght = fdf->window_hieght + 3;
	drawing(fdf->map, fdf->map_width, fdf->map_hieght, fdf);
	return 0;
}
