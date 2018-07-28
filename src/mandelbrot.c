#include "../includes/fractol.h"

void	mandelbrot(t_case *stk, int x, int y, double tp)
{
	int n;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			stk->c = (double)x / WIDTH * (stk->x_max - stk->x_min)
				+ stk->x_min;
			stk->d = (double)y / HEIGHT * (stk->y_max - stk->y_min)
				+ stk->y_min;
			n = -1;
			stk->a = 0;
			stk->b = 0;
			while (++n < stk->ite)
			{
				tp = stk->a * stk->a - stk->b * stk->b + stk->c;
				stk->b = 2 * stk->a * stk->b + stk->d;
				stk->a = tp;
				if (stk->a * stk->a + stk->b * stk->b >= 4)
					break;
			}
			if (n != stk->ite)
				fill_pixel(stk, x, y, color(stk, n, stk->ite));
		}
	}
}
