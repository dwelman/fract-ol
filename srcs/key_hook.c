#include <fractol.h>

int key_hook(int key, t_env *env)
{
	(void)env;
	printf("key = %d", key);
	if (key == EXIT)
	{
		//cleanup(env);
		exit(0);
	}
	return (0);
}