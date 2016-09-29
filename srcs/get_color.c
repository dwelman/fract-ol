#include <fractol.h>

t_col	get_color(int n, t_env *env)
{
	t_col	pal[3][5];

	if (env->color)
	{
		pal[0][0] = (t_col){188, 0, 230};
		pal[0][1] = (t_col){170, 10, 280};
		pal[0][2] = (t_col){146, 4, 202};
		pal[0][3] = (t_col){139, 0, 191};
		pal[0][4] = (t_col){128, 0, 183};
		pal[1][0] = (t_col){85, 119, 136};
		pal[1][1] = (t_col){85, 119, 136};
		pal[1][2] = (t_col){124, 160, 177};
		pal[1][3] = (t_col){218, 147, 69};
		pal[1][4] = (t_col){43, 43, 43};
		pal[2][0] = (t_col){255, 255, 255};
		pal[2][1] = (t_col){126, 155, 201};
		pal[2][2] = (t_col){190, 209, 238};
		pal[2][3] = (t_col){239, 232, 158};
		pal[2][4] = (t_col){49, 5, 58};
	}
	else
		return ((t_col){n % 256, n % 256, n % 256});
	return (pal[(env->pal - 1) % 3][n % 5]);
}