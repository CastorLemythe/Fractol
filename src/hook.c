#include "../includes/fractol.h"

int	my_mouse_funct(int button, int x, int y, t_case *stk)
{
	double min_max;
	double i_x;
	double i_y;

	min_max = stk->x_max - stk->x_min;
	i_x = (double)x / WIDTH * min_max + stk->x_min;
	i_y = (double)y / HEIGHT * min_max + stk->y_min;
	if (button == ZOOM || button == DEZOOM)
	{
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

int	my_key_funct(int keycode, t_case *stk)
{
	if (keycode == ESC)
		exit(0);
	// moove
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
	//
	if (keycode == C)
	{
		stk->color++;
		if (stk->color == 4)
			stk->color = 1;
	}
	if (keycode == J)
	{
		if (stk->j == 0)
			stk->j = 1;
		else
			stk->j = 0;
	}
	if (keycode == SPACE)
	{
		stk->ite = 50;
		stk->x_min = -2;
		stk->x_max = 2;
		stk->y_min = -2;
		stk->y_max = 2;
	}
	mlx_clear_window(stk->mlx, stk->win);
	fractol_hub(stk);
	return (0);
}
