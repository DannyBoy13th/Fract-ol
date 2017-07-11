/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:54:26 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 20:54:28 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_fdf *res)
{
	res->xp = x;
	res->yp = y;
	draw_fractal(res);
	return (0);
}

int		mouse_zoom(int key, int x, int y, t_fdf *res)
{
	if (key == 4)
	{
		if (res->dr.x2 <= res->t / 10)
		{
			res->zoom /= 10;
			res->t = res->dr.x2;
		}
		zoom_func(res, x, y, (res->zoom * -1));
		draw_fractal(res);
	}
	if (key == 5)
	{
		zoom_func(res, x, y, res->zoom);
		draw_fractal(res);
	}
	return (0);
}
