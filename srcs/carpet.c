/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:23:53 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 15:12:51 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		check_pixel(int x, int y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void	carpet(t_env *env)
{
	int		x;
	int		y;
	int		ret;
	t_col	col;

	x = -WIN_X / 2;
	y = -WIN_Y / 2;
	ret = 0;
	while (y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X / 2)
		{
			ret = check_pixel(x, y);
			if (ret == 1)
			{
				col.r = 255;
				col.g = 255;
				col.b = 255;
			}
			else
			{
				col.r = 0;
				col.g = 0;
				col.b = 0;
			}
			save_to_img(env, col, x, y);
			x++;
		}
		y++;
	}
}
