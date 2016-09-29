/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 09:38:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/09/29 08:39:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libc.h>
# include <math.h>
# include <libft.h>
# include <pthread.h>
# define WIN_X 640
# define WIN_Y 640
# define EXIT 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define R 15
# define T 17
# define Y 16
# define P 35
# define NO_THREADS 4

typedef struct	s_col
{
	float	r;
	float	g;
	float	b;
}				t_col;

typedef struct	s_frac
{
	double	new_real;
	double	old_real;
	double	new_imag;
	double	old_imag;
	int		max_iter;
}				t_frac;

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
	int			code;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		c_real;
	double		c_imag;
	double		move_x;
	double		move_y;
	int			max_n;
	t_img		img;
	int			i_x_max;
	int			i_y_max;
	int			wheel_x;
	int			wheel_y;
	int			point_x;
	int			point_y;
	double		mapped_point_x;
	double		mapped_point_y;
	int			win_x;
	int			win_y;
	int			rel_x;
	int			rel_y;
	double		zoom;
	int			lock_state;
	int			color;
	int			pal;
}				t_env;

typedef struct	s_fr_thread
{
	int		x_s;
	int		x_e;
	int		y_s;
	int		y_e;
	t_env	*env;
}				t_fr_thread;

void			make_threads(t_env *env);

void			redraw(t_env *env);

void			map_mouse(t_env *env, double range_min, double range_max);

int				mouse_move(int x, int y, t_env *env);

void			*draw_fractal(void *e);

void			mandelbrot(t_fr_thread *t);

void			julia(t_fr_thread *t);

void			burning_ship(t_fr_thread *t);

void			burning_julia(t_fr_thread *t);

int				key_hook(int key, t_env *env);

int				close_window(t_env *env);

int				mouse_hook(int key, int x, int y, t_env *env);

void			save_to_img(t_env *env, t_col col, int x, int y);

t_col			HsvToRgb(double h, double S, double V);

t_col			get_color(int n, t_env *env);

#endif
