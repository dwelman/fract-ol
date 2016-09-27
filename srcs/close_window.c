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

int	close_window(t_env *env)
{
	(void)env;
	//Add memory cleanup!
	//mlx_destroy_window(env->mlx, env->img.img);
	exit(0);
	return (0);
}