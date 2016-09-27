/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:17:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/27 11:29:17 by daviwel          ###   ########.fr       */
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

	}
	else if (key == SCROLL_UP)
	{

	}
	return (0);
}
