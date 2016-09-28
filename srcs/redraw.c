#include <fractol.h>

void	redraw(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp,
		&env->img.s, &env->img.e);
	draw_fractal(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}