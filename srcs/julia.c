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
	ft_printf("a thread");
	t_env	*env;
	double	new_real;
	double	new_imag;
	double	old_real;
	double	old_imag;
	t_col	col;
	int		i;
	int		max_iter = 255;
	int		x = 0;

	
	env = t->env;
//	c_real = -0.7;
//	c_imag = 0.27015;
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
			col.r = i % 256;
			col.g = i % 256;
			col.b = i % 256;
			save_to_img(env, col, x, t->y_s);
			x++;
		}
		t->y_s++;
	}
}
