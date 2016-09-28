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

void	mandelbrot(t_env *env)
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
	double	p_real;
	double	p_imag;

	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			//printf("y = %d, x = %d\n", y, x);
			p_real = 1.5 * (x - WIN_X / 2) / (0.5 * env->zoom * WIN_X) + env->move_x;
			p_imag = (y - WIN_Y / 2) / (0.5 * env->zoom * WIN_Y) + env->move_y;
			new_real = new_imag = old_real = old_imag = 0;
			//printf("new real = %f, new imag = %f\n", new_real, new_imag);
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
