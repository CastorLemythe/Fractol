/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <lufranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:15:26 by lufranco          #+#    #+#             */
/*   Updated: 2018/08/08 14:17:10 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		color_1(int n, int ite)
{
	int	color;

	if (n)
	{
		n = 255 - (n * 255 / ite);
		if (n <= 127)
			color = 0xffff00 + 0x000001 * (n * 2);
		else if (n <= 190)
			color = 0xffffff - 0x010100 * ((n - 127) * 4);
		else if (n <= 253)
			color = 0x0000ff - 0x000001 * ((n - 190) * 4);
		else
			color = 0x000000;
	}
	else
		color = 0x000000;
	return (color);
}

int		color_2(int n, int ite)
{
	int	color;

	if (n)
	{
		n = 255 - (n * 255 / ite);
		if (n <= 127)
			color = 0x00ff00 + 0x010000 * (n * 2);
		else if (n <= 190)
			color = 0xffff00 - 0x000100 * ((n - 127) * 4);
		else if (n <= 253)
			color = 0xff0000 - 0x010000 * ((n - 190) * 4);
		else
			color = 0x000000;
	}
	else
		color = 0x000000;
	return (color);
}

int		color_3(int n, int ite)
{
	int	color;

	if (n)
	{
		n = 255 - (n * 255 / ite);
		if (n <= 127)
			color = 0x0000ff + 0x000100 * (n * 2);
		else if (n <= 190)
			color = 0x00ffff - 0x000001 * ((n - 127) * 4);
		else if (n <= 253)
			color = 0x00ff00 - 0x000100 * ((n - 190) * 4);
		else
			color = 0x000000;
	}
	else
		color = 0x000000;
	return (color);
}

int		color(t_case *stk, int n, int ite)
{
	int	color;

	if (stk->color == 1)
		color = color_1(n, ite);
	else if (stk->color == 2)
		color = color_2(n, ite);
	else
		color = color_3(n, ite);
	return (color);
}
