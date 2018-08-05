#include "../includes/fractol.h"

void	draw_v(t_case *stk)
{
	int i;

	i = -1;
	while(++i < HEIGHT)
		fill_pixel(stk, WIDTH, i, 0xffffff);
}

void	fractol_hub(t_case *stk)
{
	double	tp;
	char	*ite;
	int		x;
	int		y;

	tp = 0.0;
	x = 0;
	y = -1;
	if (stk->type == 0)
		julia(stk, x, y, tp);
	else if (stk->type == 1)
		mandelbrot(stk, x, y, tp);
	else if (stk->type == 2)
		burning_ship(stk, x, y, tp);
	else
		mandelbar(stk, x, y, tp);
	draw_v(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->ptr_ima, 0, 0);
	ft_bzero(stk->str_ima, (WIDTH + 230) * HEIGHT * 4);
	ite = ft_strjoin("Iteration = ", ft_itoa(stk->ite));
	mlx_string_put(stk->mlx, stk->win, 5, 5, 0xffffff, ite);
	commands(stk);
	free(ite);
}

int		init_mlx(t_case *stk)
{
	int	bpp;
	int	s_l;
	int	endian;

	if ((stk->mlx = mlx_init()) == NULL)
		return (1);;
	if ((stk->win = mlx_new_window(stk->mlx, WIDTH + 230, HEIGHT, "Fractol"))
		== NULL)
		return (1);
	stk->ptr_ima = mlx_new_image(stk->mlx, WIDTH + 230, HEIGHT);
	stk->str_ima = mlx_get_data_addr(stk->ptr_ima, &(bpp), &(s_l), &(endian));
	stk->ite = 50;
	stk->x_max = 2;
	stk->x_min = -2;
	stk->y_max = 2;
	stk->y_min = -2;
	stk->c = 0;
	stk->d = 0;
	stk->j = 1;
	stk->n = 0;
	stk->color = 1;
	return (0);
}

int		fractol_type(char *type, t_case *stk)
{
	if (ft_strcmp(type, "julia") == 0)
		stk->type = 0;
	else if (ft_strcmp(type, "mandelbrot") == 0)
		stk->type = 1;
	else if (ft_strcmp(type, "burningship") == 0)
		stk->type = 2;
	else if (ft_strcmp(type, "mandelbar") == 0)
		stk->type = 3;
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_case	stk;
	void	*f;

	f = &(julia_mouse);
	if (argc != 2 || !(fractol_type(argv[1], &stk)))
	{
		ft_putstr("Usage : ./fractol \"julia\", \"mandelbrot\", ");
		ft_putendl("\"burningship\", \"mandelbar\"");
	}
	else if (HEIGHT > 800 || WIDTH > 1200)
		ft_putendl("Define -> HEIGHT or WIDTH too big");
	else if (init_mlx(&stk) == 1)
		ft_putendl("Mlx init failed...");
	else
	{
		fractol_hub(&stk);
		mlx_key_hook(stk.win, my_key_funct, &stk);
		mlx_mouse_hook(stk.win, my_mouse_funct, &stk);
		if (stk.type == 0)
			mlx_hook(stk.win, 6, 1L << 6, f, &stk);
		mlx_loop(stk.mlx);
	}
	return (0);
}
