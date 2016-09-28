/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:37:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 09:28:38 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	julia(t_env *env)
{
	double	new_real;
	double	new_imag;
	double	old_real;
	double	old_imag;
	t_col	col;
	int		i;
	int		max_iter = 500;
	int		x = 0;
	int		y = 0;

	env->c_real = -0.7;
	env->c_imag = 0.27015;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			//printf("y = %d, x = %d\n", y, x);
			new_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X) + env->move_x;
			new_imag = (y - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y) + env->move_y;
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
			save_to_img(env, col, x, y);
			x++;
		}
		y++;
	}
}
