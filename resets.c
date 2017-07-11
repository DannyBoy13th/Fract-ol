/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:46:05 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 20:46:08 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pix(int y, int x, int color, t_fdf *res)
{
	if (y >= RESO_Y || x >= RESO_X || y <= 0 || x <= 0)
		return ;
	res->addr[y * res->sl + x * 4] = color & 0x0000ff;
	res->addr[y * res->sl + x * 4 + 1] = (color >> 8) & 0xff;
	res->addr[y * res->sl + x * 4 + 2] = (color >> 16);
}

void	reset_ship(t_fdf *res)
{
	res->r_min = -2.0;
	res->r_max = 1.0;
	res->i_min = -1.0;
	res->i_max = 1.0;
	res->dr.x2 = 0.04;
	res->t = 0.1;
	res->x = 0.185476;
	res->y = 0.923938;
	res->zoom = 0.01;
	res->iter = 22;
	res->col = 0x000000;
}

void	reset_mandel(t_fdf *res)
{
	res->r_min = -2.0;
	res->r_max = 1.0;
	res->i_min = -1.0;
	res->i_max = 1.0;
	res->dr.x2 = 1.5;
	res->t = 1.5;
	res->x = -0.5;
	res->y = -0.5;
	res->zoom = 0.1;
	res->iter = 50;
	res->col = 0x950000;
}

void	reset_cluster(t_fdf *res)
{
	res->r_min = -2.0;
	res->r_max = 1.0;
	res->i_min = -1.0;
	res->i_max = 1.0;
	res->dr.x2 = 0.6;
	res->t = 1.5;
	res->x = 1.038;
	res->y = 0.25;
	res->xp = 429.0;
	res->yp = 389.0;
	res->zoom = 0.1;
	res->iter = 50;
	res->col = 0x000000;
}

void	reset_julia(t_fdf *res)
{
	res->r_min = -2.0;
	res->r_max = 1.0;
	res->i_min = -1.0;
	res->i_max = 1.0;
	res->dr.x2 = 1.4;
	res->t = 1.5;
	res->x = -0.074512;
	res->y = -0.430625;
	res->zoom = 0.1;
	res->iter = 70;
	res->xp = 239.0;
	res->yp = 239.0;
	res->col = 0x009500;
}
