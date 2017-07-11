/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:58:02 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 20:52:33 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ship_func(t_fdf *res)
{
	double r1;
	double i1;

	res->i = 1;
	while (res->i < res->iter && (res->mod.x_r * res->mod.x_r
		+ res->mod.x_i * res->mod.x_i) < 4)
	{
		res->mod.x_r = fabs(res->mod.x_r);
		res->mod.x_i = fabs(res->mod.x_i);
		r1 = res->mod.x_r * res->mod.x_r - res->mod.x_i
		* res->mod.x_i + res->mod.y_r;
		i1 = res->mod.x_r * res->mod.x_i * 2 + res->mod.y_i;
		if (res->mod.x_r == r1 && res->mod.x_i == i1)
		{
			res->col2 = 0xffb543;
			return ;
		}
		res->mod.x_r = r1;
		res->mod.x_i = i1;
		res->i++;
	}
	if (res->i == res->iter)
		res->col2 = 0xffb543;
	else
		res->col2 = res->col + res->i * 10;
}

void	mandel_func(t_fdf *res)
{
	double		r1;
	double		i1;
	int			i;

	i = 1;
	while (i < res->iter && (res->mod.x_r * res->mod.x_r
		+ res->mod.x_i * res->mod.x_i) < 4)
	{
		r1 = res->mod.x_r * res->mod.x_r - res->mod.x_i
		* res->mod.x_i + res->mod.y_r;
		i1 = res->mod.x_r * res->mod.x_i * 2 + res->mod.y_i;
		if (res->mod.x_r == r1 && res->mod.x_i == i1)
		{
			res->col2 = 0x000000;
			return ;
		}
		res->mod.x_r = r1;
		res->mod.x_i = i1;
		i++;
	}
	if (i == res->iter)
		res->col2 = 0x000000;
	else
		res->col2 = res->col + i * 1000;
}

void	cluster_func(t_fdf *res)
{
	double r1;
	double i1;

	res->i = 1;
	while (res->i < res->iter && (res->mod.x_r * res->mod.x_r
		+ res->mod.x_i * res->mod.x_i) < 4)
	{
		res->mod.x_r = cbrt(res->mod.x_r);
		res->mod.x_i = fabs(res->mod.x_i);
		r1 = res->mod.x_r * res->mod.x_r - res->mod.x_i
		* res->mod.x_i + res->mod.y_r;
		i1 = res->mod.x_r * res->mod.x_i * 2 + res->mod.y_i;
		if (res->mod.x_r == r1 && res->mod.x_i == i1)
		{
			res->col2 = 0x0cdfda;
			return ;
		}
		res->mod.x_r = r1;
		res->mod.x_i = i1;
		res->i++;
	}
	if (res->i == res->iter)
		res->col2 = 0x0cdfda;
	else
		res->col2 = res->col + res->i * 10;
}

void	jul_func(t_fdf *res)
{
	double		r1;
	double		i1;
	int			i;

	i = 1;
	while (i < res->iter && (res->mod.x_r * res->mod.x_r
		+ res->mod.x_i * res->mod.x_i) < 4)
	{
		r1 = res->mod.x_r * res->mod.x_r - res->mod.x_i
		* res->mod.x_i + res->mod.y_r;
		i1 = res->mod.x_r * res->mod.x_i * 2 + res->mod.y_i;
		if (res->mod.x_r == r1 && res->mod.x_i == i1)
		{
			res->col2 = 0x000000;
			return ;
		}
		res->mod.x_r = r1;
		res->mod.x_i = i1;
		i++;
	}
	if (i == res->iter)
		res->col2 = 0x000000;
	else
		res->col2 = res->col + i * 1000;
}

void	draw_fractal(t_fdf *res)
{
	int y;
	int x;

	y = 0;
	while (y < RESO_Y)
	{
		x = 0;
		while (x < RESO_X)
		{
			if (res->frctl == 1)
				set_mandel(res, y, x);
			if (res->frctl == 2)
				set_julia(res, y, x);
			if (res->frctl == 3)
				set_ship(res, y, x);
			if (res->frctl == 4)
				set_cluster(res, y, x);
			ft_put_pix(y, x, res->col2, res);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(res->mlx, res->win, res->img, 0, 0);
}
