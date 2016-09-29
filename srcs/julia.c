/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:37:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 08:50:02 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	iter_loop(t_env *env, t_frac frac)
{
	int	i;
	int	max_iter;

	i = 0;
	max_iter = MAX_ITER;
	while (i < max_iter)
	{
		frac.old_real = frac.new_real;
		frac.old_imag = frac.new_imag;
		frac.new_real = frac.old_real * frac.old_real - frac.old_imag *
			frac.old_imag + env->c_real;
		frac.new_imag = 2 * frac.old_real * frac.old_imag + env->c_imag;
		if ((frac.new_real * frac.new_real + frac.new_imag * frac.new_imag) > 4)
			break ;
		i++;
	}
	return (i);
}

void		julia(t_fr_thread *t)
{
	t_env	*env;
	t_frac	frac;
	int		i;
	int		x;

	x = 0;
	env = t->env;
	env->c_real = env->mapped_point_x;
	env->c_imag = env->mapped_point_y;
	while (t->y_s < t->y_e)
	{
		x = t->x_s;
		while (x < t->x_e)
		{
			frac.new_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X)
				+ env->move_x;
			frac.new_imag = (t->y_s - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y)
				+ env->move_y;
			i = iter_loop(env, frac);
			save_to_img(env, get_color(i, env), x, t->y_s);
			x++;
		}
		t->y_s++;
	}
}
