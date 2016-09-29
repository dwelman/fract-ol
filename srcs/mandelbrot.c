/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 09:47:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 11:18:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mandelbrot(t_fr_thread *t)
{
	double	new_real;
	double	new_imag;
	double	old_real;
	double	old_imag;
	int		i;
	int		max_iter = 255;
	int		x;
	double	p_real;
	double	p_imag;
	t_env	*env;

	env = t->env;
	while (t->y_s < t->y_e)
	{
		x = t->x_s;
		while (x < t->x_e)
		{
			p_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X) + env->move_x;
			p_imag = (t->y_s - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y) + env->move_y;
			new_real = new_imag = old_real = old_imag = 0;
			i = 0;
			while (i < max_iter)
			{
				old_real = new_real;
				old_imag = new_imag;
				new_real = old_real * old_real - old_imag * old_imag + p_real;
				new_imag = 2 * old_real * old_imag + p_imag;
				if ((new_real * new_real + new_imag * new_imag) > 4)
					break;
				i++;
			}
			save_to_img(env, get_color(i, env), x, t->y_s);
			x++;
		}
		t->y_s++;
	}
}
