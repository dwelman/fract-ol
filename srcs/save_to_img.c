/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 10:38:06 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/29 10:38:12 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/*
** Save color value to image.
*/

void			save_to_img(t_env *env, t_col col, int x, int y)
{
	env->img.data[(x + y * WIN_X) * 4 + 2] = (unsigned char)col.r;
	env->img.data[(x + y * WIN_X) * 4 + 1] = (unsigned char)col.g;
	env->img.data[(x + y * WIN_X) * 4 + 0] = (unsigned char)col.b;
}
