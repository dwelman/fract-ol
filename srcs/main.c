/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/03 11:06:39 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
/*
int		expose(t_env *env)
{
	if (env->win && env->img.img)
	{
		mlx_clear_window(0, env->win);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	}
	return (0);
}
*/

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	/*t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "RT");
	env.img.img = mlx_new_image(env.mlx, WIN_X, WIN_Y);
	env.img.data = mlx_get_data_addr(env.img.img, &env.img.bpp,
		&env.img.s, &env.img.e);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_loop(env.mlx);*/
	return (0);
}
