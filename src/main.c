#include "../includes/fractol.h"

int	my_key_funct(int keycode, t_case *stock)
{
	if (keycode == 53)
		exit(0);
	stock->type = 0;
	return (0);
}

void	init_mlx(t_case *stock)
{
	int bpp;
	int s_l;
	int endian;

	if (((stock->mlx = mlx_init()) == NULL) ||
	((stock->win = mlx_new_window(stock->mlx, 1200, 800, "Fractol")) == NULL))
		exit(0);
	stock->ptr_ima = mlx_new_image(stock->mlx, 1200, 800);
	stock->str_ima = mlx_get_data_addr(stock->ptr_ima, &(bpp), &(s_l), &(endian));
}

int	fractol_type(char *type, t_case *stock)
{
	if (ft_strcmp(type, "julia") == 0)
		stock->type = 0;
	else if (ft_strcmp(type, "mandelbrot") == 0)
		stock->type = 0;
	else
	{
		ft_putendl("Usage : ./fractol \"julia\", \"mandelbrot\"");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_case *stock;

	if (!(stock = (t_case *)malloc(sizeof(t_case))))
		return(-1);
	if (argc < 2)
		ft_putendl("Usage : ./fractol \"julia\", \"mandelbrot\"");
	else
	{
		if (!(fractol_type(argv[1], stock)))
			return (0);
		stock->width = 1200;
		stock->height = 800;
		init_mlx(stock);
		koch(stock);
		mlx_key_hook(stock->win, my_key_funct, stock);
		mlx_loop(stock->mlx);
	}
	return (0);
}
