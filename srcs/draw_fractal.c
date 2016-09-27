/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/27 10:57:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	draw_fractal(t_env *env, int code)
{
	mandelbrot(env);
	return ;
	(void)env;
	(void)code;
}
