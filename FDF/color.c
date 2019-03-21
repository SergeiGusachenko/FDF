/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:24:00 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/21 14:13:00 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_point current, t_point start, t_point end, t_point delta)
{
    int		red;
    int		green;
    int		blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}
