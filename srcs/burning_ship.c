/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 07:11:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 07:41:14 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	burning_ship(t_fr_thread *t)
{
	double	new_real;
	double	new_imag;
	double	old_real;
	double	old_imag;
	t_col	col;
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
			//printf("y = %d, x = %d\n", y, x);
			p_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X) + env->move_x;
			p_imag = (t->y_s - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y) + env->move_y;
			new_real = new_imag = old_real = old_imag = 0;
			//printf("new real = %f, new imag = %f\n", new_real, new_imag);
			i = 0;
			while (i < max_iter)
			{
				old_real = fabs(new_real);
				old_imag = fabs(new_imag);
				new_real = old_real * old_real - old_imag * old_imag + p_real;
				new_imag = 2 * old_real * old_imag + p_imag;
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
