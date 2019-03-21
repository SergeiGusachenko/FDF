/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:53:53 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/20 01:31:53 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		skip_digits(int		i,  char		*line)
{
	while(ft_isdigit(line[i]) || line[i] == '-')
		i++;
	return i;
}

double	*get_arr(char *line)
{
	double *arr;
	int len;
	int i;
	int j;

	j = 0;
	i = 0;
	len = ft_count_words(line,0,' ');
	arr = (double*)ft_memalloc((len+1)*sizeof(double));
	while(line[i])
	{
		if(line[i] == ' ')
			i++;
		else{
			arr[j] = ft_atoi(&(line[i]));
			j++;
			i = skip_digits(i,line);
		}
	}
	return arr;
}

void	allocate_map(t_fdf *fdf, char *line)
{
	fdf->map_width =  ft_count_words(line, 0, ' ');
	if(!(fdf->map = (double**)ft_memalloc((fdf->map_width + 1) * sizeof(double *))))
		return ;
	fdf->map[fdf->map_width] = (double*)ARREND;
	fdf->map[0] = get_arr(line);
}

void		read_map(int fd, t_fdf *fdf)
{
	char *line;
	int		i;
	int height;

	height = 0;
	i = 1;
	get_next_line(fd, &line);
	allocate_map(fdf, line);
	while(get_next_line(fd, &line))
	{
		fdf->map[i] =  get_arr(line);
		i++;
		height++;
	}
	fdf->map_hieght = height;
}
