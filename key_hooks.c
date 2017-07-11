/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:54:14 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/15 16:54:15 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_move(int key, t_fdf *res)
{
	if (key == 125)
		res->y += res->dr.x2 / 2;
	if (key == 123)
		res->x -= res->dr.x2 / 2;
	if (key == 126)
		res->y -= res->dr.x2 / 2;
	if (key == 124)
		res->x += res->dr.x2 / 2;
}

void	hook_change(int key, t_fdf *res)
{
	if (key == 18)
	{
		res->frctl = 1;
		reset_mandel(res);
	}
	if (key == 19)
	{
		res->frctl = 2;
		reset_julia(res);
	}
	if (key == 20)
	{
		res->frctl = 3;
		reset_ship(res);
	}
	if (key == 21)
	{
		res->frctl = 4;
		reset_cluster(res);
	}
}

void	hook_reset(t_fdf *res)
{
	if (res->frctl == 1)
		reset_mandel(res);
	if (res->frctl == 2)
		reset_julia(res);
	if (res->frctl == 3)
		reset_ship(res);
	if (res->frctl == 4)
		reset_cluster(res);
}

int		hook_operators(int key, t_fdf *res)
{
	if (key == 53)
		exit(0);
	if (key == 14)
		res->iter += 2;
	if (key == 12)
		res->iter -= 2;
	if (key >= 18 && key <= 21)
		hook_change(key, res);
	if (key == 48)
		res->col += 1000;
	if (key >= 123 && key <= 126)
		hook_move(key, res);
	if (key == 15)
		hook_reset(res);
	draw_fractal(res);
	return (0);
}
