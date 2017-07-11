/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:29:02 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 20:31:25 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	operations(t_fdf *res)
{
	mlx_destroy_image(res->mlx, res->img);
	res->img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->sl, &res->end);
}

void	mlx_launcher(t_fdf *res)
{
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, RESO_X, RESO_Y, "fractol");
	res->img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->sl, &res->end);
	mlx_hook(res->win, 2, 3, hook_operators, res);
	mlx_hook(res->win, 6, 3, mouse_move, res);
	mlx_hook(res->win, 4, 3, mouse_zoom, res);
	if (res->frctl == 1)
		reset_mandel(res);
	if (res->frctl == 2)
		reset_julia(res);
	if (res->frctl == 3)
		reset_ship(res);
	if (res->frctl == 4)
		reset_cluster(res);
	draw_fractal(res);
}

void	check_fractal(char *str, t_fdf *res)
{
	char *mandel;
	char *julia;
	char *ship;
	char *cluster;

	mandel = "mandelbrot";
	julia = "julia";
	cluster = "cluster";
	ship = "burningship";
	res->frctl = 0;
	if (ft_strcmp(str, mandel) == 0 ||
		ft_strcmp(str, "1") == 0)
		res->frctl = 1;
	if (ft_strcmp(str, julia) == 0 ||
		ft_strcmp(str, "2") == 0)
		res->frctl = 2;
	if (ft_strcmp(str, ship) == 0 ||
		ft_strcmp(str, "3") == 0)
		res->frctl = 3;
	if (ft_strcmp(str, cluster) == 0 ||
		ft_strcmp(str, "4") == 0)
		res->frctl = 4;
	return ;
}

void	to_string(void)
{
	ft_putstr(" _________________________________\n");
	ft_putstr("| Wrong fractal name              |\n");
	ft_putstr("|_________________________________|\n");
	ft_putstr("| Please, use following keywords: |\n");
	ft_putstr("|_________________________________|\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|   1.)     mandelbrot            |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|   2.)     julia                 |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|   3.)     burningship           |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|   4.)     cluster               |\n");
	ft_putstr("|                                 |\n");
	ft_putstr("|_________________________________|\n");
}

int		main(int argc, char **argv)
{
	static	t_fdf	res;

	if (argc != 2)
	{
		ft_putstr("Please, use 1 argument.\n");
		return (0);
	}
	check_fractal(argv[1], &res);
	if (res.frctl == 0)
	{
		to_string();
		exit(0);
	}
	mlx_launcher(&res);
	mlx_loop(res.mlx);
	return (0);
}
