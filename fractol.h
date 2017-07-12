/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:54:45 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/07/07 21:02:26 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "math.h"
# define RESO_X 820
# define RESO_Y 640

typedef struct	s_dr
{
	double		x2;
}				t_dr;

typedef struct	s_mod
{
	double		x_r;
	double		x_i;
	double		y_r;
	double		y_i;
}				t_mod;

typedef struct	s_fdf
{
	t_dr		dr;
	t_mod		mod;
	int			bpp;
	int			sl;
	int			end;
	char		**line;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	double		x;
	double		y;
	int			col;
	int			col2;
	double		xp;
	double		yp;
	int			iter;
	int			frctl;
	double		t;
	double		zoom;
	double		r_min;
	double		r_max;
	double		i_min;
	double		i_max;
	int			i;
}				t_fdf;

void			mlx_launcher(t_fdf *res);
void			draw_fractal(t_fdf *res);
void			ft_put_pix(int y, int x, int color, t_fdf *res);
void			hook_move(int key, t_fdf *res);
void			hook_rotate(int key, t_fdf *res);
int				hook_operators(int key, t_fdf *res);
int				mouse_zoom(int key, int x, int y, t_fdf *res);
void			zoom_func(t_fdf *res, double x, double y, double z);
void			to_string();
void			reset_mandel(t_fdf *res);
void			reset_julia(t_fdf *res);
void			hook_change(int key, t_fdf *res);
void			hook_reset(t_fdf *res);
int				mouse_move(int x, int y, t_fdf *res);
void			set_mandel(t_fdf *res, int x, int y);
void			set_julia(t_fdf *res, int x, int y);
void			mandel_func(t_fdf *res);
void			jul_func(t_fdf *res);
int				mouse_change(int key, int x, int y, t_fdf *res);
void			set_ship(t_fdf *res, int x, int y);
void			ship_func(t_fdf *res);
void			reset_ship(t_fdf *res);
void			test_func(t_fdf *res);
void			set_cluster(t_fdf *res, int x, int y);
void			reset_cluster(t_fdf *res);
void			cluster_func(t_fdf *res);

#endif
