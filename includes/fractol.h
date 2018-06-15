#ifndef FRACTOL_H
# define FRACTOL_H
# include "./../libft/libft.h"
# include "./../miniLibX/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_case
{
	void	*mlx;
	void	*win;
	void	*ptr_ima;
	char	*str_ima;
	int	type;
	int	width;
	int	height;
}		t_case;

void	fill_pixel(t_case *stock, int x, int y, int color);
void	koch(t_case *stock);
#endif
