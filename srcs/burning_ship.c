/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 09:47:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 09:07:13 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	iter_loop(t_frac frac)
{
	int	i;
	int	max_iter;

	i = 0;
	max_iter = MAX_ITER;
	while (i < max_iter)
	{
		frac.old_real = fabs(frac.new_real);
		frac.old_imag = fabs(frac.new_imag);
		frac.new_real = frac.old_real * frac.old_real - frac.old_imag
			* frac.old_imag + frac.p_real;
		frac.new_imag = 2 * frac.old_real * frac.old_imag + frac.p_imag;
		if ((frac.new_real * frac.new_real + frac.new_imag * frac.new_imag) > 4)
			break ;
		i++;
	}
	return (i);
}

void		burning_ship(t_fr_thread *t)
{
	t_frac	frac;
	int		i;
	int		x;
	t_env	*env;

	env = t->env;
	while (t->y_s < t->y_e)
	{
		x = t->x_s;
		while (x < t->x_e)
		{
			frac.p_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X)
				+ env->move_x;
			frac.p_imag = (t->y_s - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y)
				+ env->move_y;
			frac.new_real = 0;
			frac.new_imag = 0;
			frac.old_real = 0;
			frac.old_imag = 0;
			i = iter_loop(frac);
			save_to_img(env, get_color(i, env), x, t->y_s);
			x++;
		}
		t->y_s++;
	}
}
