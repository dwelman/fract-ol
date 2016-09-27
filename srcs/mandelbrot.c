#include <fractol.h>

double map_to_real(int x, double min_r, double max_r)
{
	double range;
	range = max_r - min_r;
	return (x * (range / WIN_X) + min_r);
}

double map_to_imaginary(int y, double min_i, double max_i)
{
	double range;

	range = max_i - min_i;
	return (y * (range / WIN_Y) + min_i);
}

int	find_mandelbrot(double cr, double ci, int max_iterations)
{
	int i;
	double zr;
	double zi;
	double temp;

	zr = 0.0F;
	zi = 0.0F;
	i = 0;
	while (i < max_iterations && zr * zr + zi * zi < 4.0F)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_env *env)
{
	int		x;
	int		y;
	int		n;
	t_col	col;
	
	env->max_n = 255;
	env->max_r = 0.7;
	env->min_r = -1.5;
	env->max_i = 1.0;
	env->min_i = -1.0;
	y = 0;
	col = (t_col){0.0, 0.0, 0.0};
	while (y < env->win_y)
	{
		x = 0;
		while (x < env->win_x)
		{
			env->cr = map_to_real(x, env->min_r, env->max_r);
			env->ci = map_to_imaginary(y, env->min_i, env->max_i);
			n = find_mandelbrot(env->cr, env->ci, env->max_n);
			if ( n < env->max_n )
			{
				 double log_zn = log( x*x + y*y ) / 2;
				 double nu = log( log_zn / log(2) ) / log(2);
				 n = n + 1 - nu;
			}
			//printf ("col = (%f, %f, %f)\n n = %d\n", col.r, col.g, col.b, n);
			printf ("n = %d\n", n);
			col.r = (int)(n * sinf(n * 0.01745329252F)) % 256;
			col.g = (n * n) % 256;
			col.b = n % 256;
			save_to_img(env, col, x, y);
			x++;
		}
		y++;
	}
}