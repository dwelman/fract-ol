/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:37:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 09:58:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	julia(t_fr_thread *t)
{
	t_env	*env;
	double	new_real;
	double	new_imag;
	double	old_real;
	double	old_imag;
	int		i;
	int		max_iter = 255;
	int		x = 0;

	env = t->env;
	env->c_real = env->mapped_point_x;
	env->c_imag = env->mapped_point_y;
	while (t->y_s < t->y_e)
	{
		x = t->x_s;
		while (x < t->x_e)
		{
			//printf("y = %d, x = %d\n", y, x);
			new_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X) + env->move_x;
			new_imag = (t->y_s - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y) + env->move_y;
			//printf("new real = %f, new imag = %f\n", new_real, new_imag);
			i = 0;
			while (i < max_iter)
			{
				old_real = new_real;
				old_imag = new_imag;
				new_real = old_real * old_real - old_imag * old_imag + env->c_real;
				new_imag = 2 * old_real * old_imag + env->c_imag;
				if ((new_real * new_real + new_imag * new_imag) > 4)
					break;
				i++;
			}
			//ft_printf("I = %d\n", i);
			//t_col test = HsvToRgb(i % 256, i, 255 * (i < max_iter));
			save_to_img(env, get_color(i, env), x, t->y_s);
			x++;
		}
		t->y_s++;
	}
}
