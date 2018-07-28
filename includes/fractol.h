#ifndef FRACTOL_H
# define FRACTOL_H
# include "./../libft/libft.h"
# include "./../miniLibX/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

#define WIDTH 1200
#define HEIGHT 800
#define ZOOM 4
#define DEZOOM 5
#define ESC 53
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125
#define C 8
#define J 38
#define SPACE 49

typedef struct	s_case
{
	void	*mlx;
	void	*win;
	void	*ptr_ima;
	char	*str_ima;
	int	type;
	int	ite;
	int	color;
	int	j;
	double	a;
	double	b;
	double	c;
	double	d;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}		t_case;

void	fill_pixel(t_case *stk, int x, int y, int color);
void	mandelbrot(t_case *stk, int x, int y, double tp);
void	burning_ship(t_case *stk, int x, int y, double tp);
void	julia(t_case *stk, int x, int y, double tp);
void	fractol_hub(t_case *stk);
int	color(t_case *stk, int n, int ite);
int	julia_mouse(int x, int y, t_case *stk);
int	my_mouse_funct(int button, int x, int y, t_case *stk);
int	my_key_funct(int keycode, t_case *stk);
#endif
