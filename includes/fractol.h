/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 09:38:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/09/28 08:17:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libc.h>
# include <math.h>
# include <libft.h>
# define WIN_X 640
# define WIN_Y 640
# define EXIT 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MANDELBROT 1
# define JULIA 2

typedef struct	s_col
{
	float	r;
	float	g;
	float	b;
}				t_col;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			s;
	int			e;
	char		id;
	int			x;
	int			y;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		cr;
	double		ci;
	int			max_n;
	t_img		img;
	int			i_x_max;
	int			i_y_max;
	int			wheel_x;
	int			wheel_y;
	double		zoom;
}				t_env;

void			draw_fractal(t_env *env, int code);

void			julia(t_env *env);

void			mandelbrot(t_env *env);

int				key_hook(int key, t_env *env);

int				close_window(t_env *env);

int				mouse_hook(int key, int x, int y, t_env *env);

void			save_to_img(t_env *env, t_col col, int x, int y);

#endif
