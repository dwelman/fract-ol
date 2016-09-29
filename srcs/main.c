/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 07:50:29 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		expose(t_env *env)
{
	if (env->win && env->img.img)
	{
		ft_printf("exposing");
		mlx_clear_window(0, env->win);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	}
	return (0);
}

int		arg_check(int argc, char **argv)
{
	int	ret;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Usage - fractol [option]\n", 2);
		ft_putstr_fd("\t1 - Mandelbrot\n\t2 - Julia\n\t3 - Burning ship\n", 2);
		ft_putstr_fd("\t4 - Burning Julia\n", 2);
		exit(-1);
	}
	else
	{
		ret = ft_atoi(argv[1]);
		if (ret > 0 && ret < 5)
		{
			return (ret);
		}
		else
			return (1);
	}
}

void	init_env(t_env *env)
{
	env->oldx = 0;
	env->oldy = 0;
	env->pal = 2;
	env->color = 0;
	env->zoom = 1;
	env->move_x = 0;
	env->move_y = 0;
	env->win_x = WIN_X;
	env->win_y = WIN_Y;
	env->rel_x = 0;
	env->rel_y = 0;
	env->mapped_point_x = -0.7;
	env->mapped_point_y = 0.27015;
	env->lock_state = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Fract-ol");
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
		&env->img.s, &env->img.e);
}

int		main(int argc, char **argv)
{
	t_env	env;

	env.code = arg_check(argc, argv);
	init_env(&env);
	make_threads(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_hook(env.win, 6, 1L << 6, &mouse_move, &env);
	mlx_mouse_hook(env.win, &mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
