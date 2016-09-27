/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:17:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/27 11:29:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse_hook(int key, int x, int y, t_env *env)
{
	printf("BUTTON: %d\n", key);
	printf("x : %d, y : %d\n", x, y);
	(void)env;
/*	if (key == SCROLL_DOWN)
	{
		env->wheel_x = x;
		env->wheel_y = y;
	}
	else if (key == SCROLL_UP)
	{
		env->wheel_x = x;
		env->wheel_y = y;
		//env->win_x += env->wheel_x;
		//env->win_y += env->wheel_y;
	}
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
		&env->img.s, &env->img.e);
	draw_fractal(env, 1);*/
	return (0);
}
