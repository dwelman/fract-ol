/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:17:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 08:25:14 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse_hook(int key, int x, int y, t_env *env)
{
	printf("BUTTON: %d\n", key);
	printf("x : %d, y : %d\n", x, y);
	(void)env;
	if (key == SCROLL_DOWN)
	{
		env->wheel_x = x;
		env->wheel_y = y;
		env->zoom -= 0.5;
		if (env->zoom == 0)
			env->zoom = -0.5;
	}
	else if (key == SCROLL_UP)
	{
		env->wheel_x = x;
		env->wheel_y = y;
		env->zoom += 0.5;
		if (env->zoom == 0)
			env->zoom = 0.5;
	}
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
		&env->img.s, &env->img.e);
	draw_fractal(env, 1);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
