/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 10:05:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook(int key, t_env *env)
{
	(void)env;
	printf("key = %d", key);
	if (key == EXIT)
	{
		//cleanup(env);
		exit(0);
	}
	if (key == 123) //LEFT
	{
		env->move_x -= 0.06 / env->zoom;
	}
	if (key == 124) //RIGHT
	{
		env->move_x += 0.06 / env->zoom;
	}
	if (key == 126) //UP
	{
		env->move_y -= 0.06 / env->zoom;
	}
	if (key == 125) //DOWN
	{
		env->move_y += 0.06 / env->zoom;
	}
	if (key == 15) //R
	{
		env->move_x = 0;
		env->move_y = 0;
		env->zoom = 1;
	}
	mlx_destroy_image(env->mlx, env->img.img);
    env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
    env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
	        &env->img.s, &env->img.e);
    draw_fractal(env);
    mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
