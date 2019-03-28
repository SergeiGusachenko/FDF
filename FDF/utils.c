/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:45:19 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/27 16:46:32 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector	to_disp(t_vector vec, t_fdf *fdf)
{
	vec.x1 = fdf->window_width + vec.x1 * fdf->image_size;
	vec.x0 = fdf->window_width + vec.x0 * fdf->image_size;
	vec.y1 = fdf->window_hieght + vec.y1 * fdf->image_size;
	vec.y0 = fdf->window_hieght + vec.y0 * fdf->image_size;
	return (vec);
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * end + percentage * start));
}
