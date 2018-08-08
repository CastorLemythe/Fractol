/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <lufranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:14:12 by lufranco          #+#    #+#             */
/*   Updated: 2018/08/08 14:36:26 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./../libft/libft.h"
# include "./../miniLibX/mlx.h"
# include <math.h>
# include <float.h>

# define WIDTH 1200
# define HEIGHT 800
# define ZOOM 4
# define DEZOOM 5
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define C 8
# define J 38
# define N 45
# define M 46
# define L 37
# define SPACE 49

typedef struct	s_case
{
	void	*mlx;
	void	*win;
	void	*ptr_ima;
	char	*str_ima;
	int		type;
	int		ite;
	int		color;
	int		j;
	int		n;
	double	a;
	double	b;
	double	c;
	double	d;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_case;

void			fill_pixel(t_case *stk, int x, int y, int color);
void			mandelbrot(t_case *stk, int x, int y, double tp);
void			burning_ship(t_case *stk, int x, int y, double tp);
void			julia(t_case *stk, int x, int y, double tp);
void			mandelbar(t_case *stk, int x, int y, double tp);
void			fractol_hub(t_case *stk);
void			commands(t_case *stk);
int				color(t_case *stk, int n, int ite);
int				julia_mouse(int x, int y, t_case *stk);
int				my_mouse_funct(int button, int x, int y, t_case *stk);
int				my_key_funct(int keycode, t_case *stk);
#endif
