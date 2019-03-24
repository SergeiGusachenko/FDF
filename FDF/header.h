/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:45:55 by sgusache          #+#    #+#             */
/*   Updated: 2019/03/22 20:56:29 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include "../get_next_line/get_next_line.h"
#include "../get_next_line/libft/libft.h"
# include <fcntl.h>
#include <math.h>
#define HIEGHT	1000
#define WIDTH	1000
#define ESC			53
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define MOVE_RIGHT 124
#define MOVE_LEFT 123
#define MOVE_UP 126
#define MOVE_DOWN 125
#define ARREND  NULL


typedef struct		s_point
{
	double x;
	double y;
}					t_point;

typedef struct		s_vector
{
	double x0;
	double y0;
	double x1;
	double y1;
	double z;
	int		image_size;
	int		window_width;
}							t_vector;

typedef struct		s_fdf
{
	void*	mlx;
	void*	win;
	double	**map;
	int		map_width;
	int		map_hieght;
	int		image_size;
	int		window_width;
	int		window_hieght;
}								t_fdf;

int							get_color(t_vector vec, int x, int y, int current_color);
void						line(t_fdf fdf);
int							key_press(int key,t_fdf *fdf);
void						read_map(int fd, t_fdf *fdf);
void						throw_error(char *str);
void						drawing(double **map, int width, int hieght, t_fdf* fdf);
void						to_iso(double *x, double *y, double z);
void						print_line(t_vector vector, t_fdf *fdf);
void						print_map(int **map, t_fdf *fdf);
int							scroll(int key, t_fdf *fdf);
int							hook_mouse(int button, int x, int y, t_fdf *fdf);
#endif
