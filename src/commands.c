#include "../includes/fractol.h"

void	commands(t_case *stk)
{
	int c;
	int w;

	w = WIDTH + 15;
	c = 0xffffff;
	mlx_string_put(stk->mlx, stk->win, w, 5, c, "GENERAL");
	mlx_string_put(stk->mlx, stk->win, w, 35, c, "ESC : Quit");
	mlx_string_put(stk->mlx, stk->win, w, 50, c, "SPACE : Reset");
	mlx_string_put(stk->mlx, stk->win, w, 65, c, "C : Color");
	mlx_string_put(stk->mlx, stk->win, w, 80, c, "L : Less Iteration");
	mlx_string_put(stk->mlx, stk->win, w, 95, c, "M : More Iteration");
	mlx_string_put(stk->mlx, stk->win, w, 110, c, "< : Move Left");
	mlx_string_put(stk->mlx, stk->win, w, 125, c, "> : Move Right");
	mlx_string_put(stk->mlx, stk->win, w, 140, c, "^ : Move Up");
	mlx_string_put(stk->mlx, stk->win, w, 155, c, "v : Move Down");
	mlx_string_put(stk->mlx, stk->win, w, 185, c, "-------------------");
	mlx_string_put(stk->mlx, stk->win, w, 215, c, "Julia");
	mlx_string_put(stk->mlx, stk->win, w, 245, c, "J : Mouse On/Off");
	mlx_string_put(stk->mlx, stk->win, w, 260, c, "N : Negativ On/Off");
	mlx_string_put(stk->mlx, stk->win, w, 290, c, "-------------------");
	mlx_string_put(stk->mlx, stk->win, w, 320, c, "MOUSE");
	mlx_string_put(stk->mlx, stk->win, w, 350, c, "SROLL : Zoom/Dezoom");
	mlx_string_put(stk->mlx, stk->win, w, 380, c, "-------------------");
}
