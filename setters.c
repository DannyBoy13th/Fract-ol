/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:32:46 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 20:38:10 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_func(t_fdf *res, double x, double y, double z)
{
	double strt_x;
	double strt_y;
	double strt_x1;
	double strt_y2;

	strt_x = (res->r_max - res->r_min) * res->dr.x2;
	strt_y = (res->i_max - res->i_min) * res->dr.x2;
	res->dr.x2 += z;
	strt_x1 = (res->r_max - res->r_min) * res->dr.x2;
	strt_y2 = (res->i_max - res->i_min) * res->dr.x2;
	res->x -= (x / RESO_X) * (strt_x1 - strt_x);
	res->y -= (y / RESO_Y) * (strt_y2 - strt_y);
}

void		set_ship(t_fdf *res, int x, int y)
{
	res->mod.x_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.x_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	res->mod.y_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.y_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	ship_func(res);
}

void		set_mandel(t_fdf *res, int x, int y)
{
	res->mod.x_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.x_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	res->mod.y_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.y_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	mandel_func(res);
}

void		set_cluster(t_fdf *res, int x, int y)
{
	res->mod.x_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.x_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	res->mod.y_r = ((res->xp / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.y_i = ((res->yp / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	cluster_func(res);
}

void		set_julia(t_fdf *res, int x, int y)
{
	res->mod.x_r = (((double)y / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.x_i = (((double)x / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	res->mod.y_r = ((res->xp / RESO_X) * (res->r_max - res->r_min))
	* res->dr.x2 + res->r_min + (res->x);
	res->mod.y_i = ((res->yp / RESO_Y) * (res->i_max - res->i_min))
	* res->dr.x2 + res->i_min + (res->y);
	jul_func(res);
}
