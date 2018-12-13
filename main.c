#include <stdio.h>
#include <mlx.h>
#include <time.h>
#include <stdlib.h>
#include "libft/libft.h"

void *mlx_ptr;
void *win_ptr;

void	draw_line(int x, int y, int ex, int ey)
{
	
}

int		deal_key(int key, char *param)
{
	int i;
	long color;
//	char p[2];
//
//	mlx_clear_window(mlx_ptr, win_ptr);
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(key));
	if (key == 51)
	{
		mlx_clear_window(mlx_ptr, win_ptr);
		return (0);
	}
	i = 0;
	while (i < 50000)
	{
		if (rand() % 2 == 0 || rand() % 2 == 1)
			color = 0x00000000;
		else
			color = 0x00454545;
		mlx_pixel_put(mlx_ptr, win_ptr, rand() % 1920, rand() % 1280, color);
		i++;
	}
	return 0;
}

int main() {


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1280, "mlx");

    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FA0C1D);
    mlx_loop_hook(mlx_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr);
    printf("Hello, World!\n");

    return 0;
}