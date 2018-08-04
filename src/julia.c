#include "../includes/fractol.h"

int		julia_mouse(int x, int y, t_case *stk)
{
	if (stk->j == 1 && stk->n == 0)
	{
		stk->c = (double)x / WIDTH;
		stk->d = (double)y / HEIGHT;
		mlx_clear_window(stk->mlx, stk->win);
		fractol_hub(stk);
	}
	else if (stk->j == 1 && stk->n == 1)
	{
		stk->c = -(double)x / WIDTH;
		stk->d = -(double)y / HEIGHT;
		mlx_clear_window(stk->mlx, stk->win);
		fractol_hub(stk);
	}
	return (0);
}

void	julia(t_case *stk, int x, int y, double tp)
{
	int	n;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			stk->a = (double)x / WIDTH * (stk->x_max - stk->x_min)
				+ stk->x_min;
			stk->b = (double)y / HEIGHT * (stk->y_max - stk->y_min)
				+ stk->y_min;
			n = -1;
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
