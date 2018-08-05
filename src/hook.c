#include "../includes/fractol.h"

int		my_mouse_funct(int button, int x, int y, t_case *stk)
{
	double	min_max;
	double	i_x;
	double	i_y;

	if (button == ZOOM || button == DEZOOM)
	{
		min_max = stk->x_max - stk->x_min;
		i_x = (double)x / WIDTH * min_max + stk->x_min;
		i_y = (double)y / HEIGHT * min_max + stk->y_min;
		if (button == ZOOM && min_max > 0.000001)
			min_max *= 0.9;
		else if (button == DEZOOM && min_max < 4)
			min_max *= 1.1;
		if (min_max > 0.000001 && min_max < 4)
			stk->ite = (button == 4) ? stk->ite + 3 : stk->ite - 3;
		stk->x_max = i_x + min_max / 2;
		stk->x_min = i_x - min_max / 2;
		stk->y_max = i_y + min_max / 2;
		stk->y_min = i_y - min_max / 2;	
		mlx_clear_window(stk->mlx, stk->win);
		fractol_hub(stk);
	}
	return (0);
}

int		hook_2(int keycode, t_case *stk)
{
	if (keycode == LEFT)
	{
		stk->x_min -= ((double)5 / WIDTH) * (stk->x_max - stk->x_min);
		stk->x_max -= ((double)5 / WIDTH) * (stk->x_max - stk->x_min);
	}
	if (keycode == RIGHT)
	{
		stk->x_min += ((double)5 / WIDTH) * (stk->x_max - stk->x_min);
		stk->x_max += ((double)5 / WIDTH) * (stk->x_max - stk->x_min);
	}
	if (keycode == DOWN)
	{
		stk->y_min += ((double)5 / HEIGHT) * (stk->y_max - stk->y_min);
		stk->y_max += ((double)5 / HEIGHT) * (stk->y_max - stk->y_min);
	}
	if (keycode == UP)
	{
		stk->y_min -= ((double)5 / HEIGHT) * (stk->y_max - stk->y_min);
		stk->y_max -= ((double)5 / HEIGHT) * (stk->y_max - stk->y_min);
	}
	if (keycode == L || keycode == M)
		stk->ite = (keycode == L) ? stk->ite - 10 : stk->ite + 10;
	mlx_clear_window(stk->mlx, stk->win);
	fractol_hub(stk);
	return (0);
}

int		my_key_funct(int keycode, t_case *stk)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(stk->mlx, stk->ptr_ima);
		mlx_destroy_window(stk->mlx, stk->win);
		exit(0);
	}
	if (keycode == C)
	{
		stk->color++;
		if (stk->color == 4)
			stk->color = 1;
	}
	if (keycode == J)
		stk->j = (stk->j == 0) ? 1 : 0;
	if (keycode == N)
		stk->n = (stk->n == 0) ? 1 : 0;
	if (keycode == SPACE)
	{
		stk->ite = 50;
		stk->color = 1;
		stk->x_min = -2;
		stk->x_max = 2;
		stk->y_min = -2;
		stk->y_max = 2;
	}
	return (hook_2(keycode, stk));
}
