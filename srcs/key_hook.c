/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 09:24:10 by daviwel          ###   ########.fr       */
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
		
	}
	if (key == 124) //RIGHT
	{

	}
	return (0);
}
