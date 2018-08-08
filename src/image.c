/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <lufranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:15:31 by lufranco          #+#    #+#             */
/*   Updated: 2018/08/08 14:15:42 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fill_pixel(t_case *stk, int x, int y, int color)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	int				coord;

	blue = (color & 0xff);
	green = (color & 0xff00) >> 8;
	red = (color & 0xff0000) >> 16;
	if (x >= 0 && x < WIDTH + 230 && y >= 0 && y < HEIGHT)
	{
		coord = (4 * (WIDTH + 230) * y) + 4 * x;
		stk->str_ima[coord] = blue;
		coord++;
		stk->str_ima[coord] = green;
		coord++;
		stk->str_ima[coord] = red;
	}
}
