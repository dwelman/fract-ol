/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:17:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 10:05:44 by daviwel          ###   ########.fr       */
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
	draw_fractal(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

void	map_mouse(t_env *env, double range_min, double range_max)
{
	double range;

	range = range_max - range_min;
	if (range < 0)
		range = 1.0F;
	env->mapped_point_x = range_min + ((double)env->point_x / (double)env->win_x) * range;
	env->mapped_point_y = range_min + ((double)env->point_y / (double)env->win_y) * range;

}

int		mouse_move(int x, int y, t_env *env)
{
	static int	oldx = 0;
	static int	oldy = 0;

	if (x <= env->win_x && x >= 0
		&& y <= env->win_y && y >= 0)
	{
		if (env->zoom == 1)
		{
			env->point_x = x;
			env->point_y = y;
		}
		else 
		{
			if (abs(oldx - x) >= env->zoom * 5.0)
			{
				env->point_x = (oldx - x > 0) ? env->point_x + 1 / env->zoom : env->point_x -  1/ env->zoom;
				oldx = x;
			}
			if (abs(oldy - y) >= env->zoom * 5.0)
			{
				env->point_y = (oldy - y > 0) ? env->point_y + 1 / env->zoom: env->point_y - 1 / env->zoom;
				oldy = y;
			}
		}
		map_mouse(env, -1.0F, 1.0F);
		mlx_destroy_image(env->mlx, env->img.img);
		env->img.img = mlx_new_image(env->mlx, env->win_x, env->win_y);
		env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
		&env->img.s, &env->img.e);
		draw_fractal(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		printf("x = %F, y = %F\n", env->mapped_point_x, env->mapped_point_y);
	}
	return (0);
}
