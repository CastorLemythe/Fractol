#include "../includes/fractol.h"

void	fill_pixel(t_case *stock, int x, int y, int color)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	int		coord;

	blue = (color & 0xff);
	green = (color & 0xff00) >> 8;
	red = (color & 0xff0000) >> 16;
	if (x >= 0 && x < stock->width && y >= 0 && y < stock->height)
	{
		coord = (4 * stock->width * y) + 4 * x;
		stock->str_ima[coord] = blue;
		coord++;
		stock->str_ima[coord] = green;
		coord++;
		stock->str_ima[coord] = red;
	}
}
