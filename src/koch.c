#include "../includes/fractol.h"

//(a + bi)^2 + c + di
//(600 + 400i)^2 + 0.3 + 0.5i
//(600 * 600) + (2 * 600 * i400) - (400 * 400) + 0.3 + 0.5i

void	koch(t_case *stock)
{
	int x;
	int y;
	double a = 0;
	double b = 0;
	double c;
	double d;
	double tmp;
	int n;

	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 1200)
		{
			c = (double)x / 1200 * 4 - 2;
			d = (double)y / 800 * 4 - 2;
			n = -1;
			a = 0;
			b = 0;
			while (++n < 100)
			{
				tmp = a * a - b * b + c;
				b = 2 * a * b + d;
			//	b = fabs(b);
			//	a = fabs(tmp);
				a = tmp;
				if (a * a - b * b >= 4)
					break;
			}
			if (n < 100)
				fill_pixel(stock, x, y, 0x00ff00);
		}
	}
	mlx_put_image_to_window(stock->mlx, stock->win, stock->ptr_ima, 0, 0);
}
