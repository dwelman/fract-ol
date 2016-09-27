/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 09:38:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/09/27 10:53:45 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libc.h>
# include <math.h>
# include <libft.h>
# define WIN_X 1280
# define WIN_Y 720
# define EXIT 53
# define MANDELBROT 1
# define JULIA 2

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
	t_img		img;
}				t_env;

void			draw_fractal(t_env *env, int code);

int				key_hook(int key, t_env *env);

int				close_window(t_env *env);

#endif
