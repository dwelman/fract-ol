/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:17:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 07:50:01 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_hook(int key, int x, int y, t_env *env)
{
	double	relx;
	double	rely;

	relx = x - (env->win_x / 2);
	rely = y - (env->win_y / 2);
	if (key == SCROLL_DOWN)
	{
		env->zoom /= 1.2;
		env->move_x -= relx / ((env->win_x) * (env->zoom / 2));
		env->move_y -= rely / ((env->win_y) * (env->zoom / 2));
	}
	else if (key == SCROLL_UP)
	{
		env->zoom *= 1.2;
		env->move_x += relx / (env->win_x * env->zoom);
		env->move_y += rely / (env->win_y * env->zoom);
	}
	redraw(env);
	return (0);
}

void	map_mouse(t_env *env, double range_min, double range_max)
{
	double range;

	range = range_max - range_min;
	if (range < 0)
		range = 1.0F;
	env->mapped_point_x = range_min + ((double)env->point_x
			/ (double)env->win_x) * range;
	env->mapped_point_y = range_min + ((double)env->point_y
			/ (double)env->win_y) * range;
}

int		mouse_move(int x, int y, t_env *env)
{
	if (x <= env->win_x && x >= 0
		&& y <= env->win_y && y >= 0 && !env->lock_state)
	{
		if (env->zoom == 1)
		{
			env->point_x = x;
			env->point_y = y;
		}
		else
		{
			if ((float)abs(env->oldx - x) >= env->zoom * 2.0)
			{
				P_X = (env->oldx - x > 0) ? P_X - 1 : P_X + 1;
				env->oldx = x;
			}
			if ((float)abs(env->oldy - y) >= env->zoom * 2.0)
			{
				P_Y = (env->oldy - y > 0) ? P_Y - 1 : P_Y + 1;
				env->oldy = y;
			}
		}
		map_mouse(env, -1.0F, 1.0F);
		redraw(env);
	}
	return (0);
}
