/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/29 07:53:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	close_window(void)
{
	exit(0);
}

int	key_hook(int key, t_env *env)
{
	if (key == EXIT)
		exit(0);
	if (key == LEFT)
		env->move_x -= 0.06 / env->zoom;
	if (key == RIGHT)
		env->move_x += 0.06 / env->zoom;
	if (key == UP)
		env->move_y -= 0.06 / env->zoom;
	if (key == DOWN)
		env->move_y += 0.06 / env->zoom;
	if (key == R)
	{
		env->move_x = 0;
		env->move_y = 0;
		env->zoom = 1;
	}
	if (key == T)
		env->lock_state = !env->lock_state;
	if (key == Y)
		env->color = !env->color;
	redraw(env);
	return (0);
}
