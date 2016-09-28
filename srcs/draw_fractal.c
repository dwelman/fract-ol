/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:51:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/28 10:06:30 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	*draw_fractal(void *t)
{
	t_fr_thread *temp;

	temp = (t_fr_thread*)t;
	if (temp->env->code == 1)
		mandelbrot(temp->env);
	else if (temp->env->code == 2)
	{
		julia((t_fr_thread*)t);
	}
	return (NULL);
}

void	make_threads(t_env *env)
{
	t_fr_thread	bounds[NO_THREADS];
	pthread_t	thread_id[NO_THREADS];
	int			i;
	t_env		e[NO_THREADS];
	int			d;

	d = -1;
	while (++d < NO_THREADS)
		e[d] = *env;
	i = -1;
	bounds[0] = (t_fr_thread){0, WIN_X, 0, WIN_Y / 4, &e[0]};
	bounds[1] = (t_fr_thread){0, WIN_X, WIN_Y / 4,
		WIN_Y / 4 * 2, &e[1]};
	bounds[2] = (t_fr_thread){0, WIN_X, WIN_Y / 4 * 2,
		WIN_Y / 4 * 3, &e[2]};
	bounds[3] = (t_fr_thread){0, WIN_X, WIN_Y / 4 * 3,
		WIN_Y, &e[3]};
	while (++i < NO_THREADS)
		pthread_create(&thread_id[i], NULL, draw_fractal, &bounds[i]);
	i = -1;
	while (++i < NO_THREADS)
		pthread_join(thread_id[i], NULL);
}
