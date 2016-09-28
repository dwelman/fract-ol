/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 10:08:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook(int key, t_env *env)
{
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
	if (key == 17)
	{
		env->lock_state = !env->lock_state;
	}
	redraw(env);
	return (0);
}
