#include "fdf.h"

void *mlx_ptr;
void *win_ptr;
int coords[5] = {0, 0, 0, 0, 0};

//void	draw_line(int x, int y, int ex, int ey)
//{
//
//}

void	draw_map(t_init *init)
{
	int i;
	int j;
	int width = 0;
	int height = 0;

	i = 0;
	while (i < init->s_map->height)
	{
		j = 0;
		width = 0;
		while (j < init->s_map->width)
		{
			mlx_string_put(init->mlx_ptr, init->win_ptr, width, height, 0x00FA0C1D, ft_itoa((init->s_map->map)[i][j]));
			width += 20;
			j++;
		}
		height += 20;
		i++;
	}
}

void line(int x0, int y0, int x1, int y1, int color) {
//	double size;
//
//	size = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
//for (double t = 0; t < 1; t += (double)1/size) {
//int x = (int)(x0 * (1-t) + x1 * t);
//int y = (int)(y0 * (1-t) + y1 * t);
//mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//}
//}
//void line(int x0, int y0, int x1, int y1, long color) {
//	int steep = 0;
//	if (abs(x0-x1) < abs(y0-y1)) {
//		ft_swap(&x0, &y0);
//		ft_swap(&x1, &y1);
//		steep = 1;
//	}
//	if (x0>x1) {
//		ft_swap(&x0, &x1);
//		ft_swap(&y0, &y1);
//	}
//	int dx = x1-x0;
//	int dy = y1-y0;
//	double derror = abs((double)dy/(double)dx);
//	double error = 0;
//	int y = y0;
//	for (int x=x0; x<=x1; x++) {
//		if (steep) {
//			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//		} else {
//			mlx_pixel_put(mlx_ptr, win_ptr, y, x, color);
//		}
//		error += derror;
//
//		if (error > 0.5) {
//			y += (y1 > y0 ? 1 : -1);
//			error -= 1;
//		}
//	}
//}
//void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
//int steep = 0;
//int absx = x0 - x1;
//int absy = y0 - y1;
//if (abs(absx) < abs(absy)) { // if the line is steep, we transpose the image
//ft_swap(&x0, &y0);
//ft_swap(&x1, &y1);
//steep = 1;
//}
//if (x0>x1) { // make it left-to-right
//ft_swap(&x0, &x1);
//ft_swap(&y0, &y1);
//}
//
//for (int x=x0; x<=x1; x++) {
//double t = (x-x0)/(double)(x1-x0);
//int y = (int)((double)y0 * ((double)1 - t) + (double)y1 * t);
//if (steep) {
//	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color); // if transposed, de-transpose
//} else {
//	mlx_pixel_put(mlx_ptr, win_ptr, y, x, color);
//}
//}

		int dx = x1 - x0;
		int dy = y1 - y0;
		dx = abs(dx);
		dy = abs(dy);
		int sx = x1 >= x0 ? 1 : -1;
		int sy = y1 >= y0 ? 1 : -1;

		if (dy <= dx)
		{
			int d = (dy << 1) - dx;
			int d1 = dy << 1;
			int d2 = (dy - dx) << 1;
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
			for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
			{
				if ( d >0)
				{
					d += d2;
					y += sy;
				}
				else
					d += d1;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			}
		}
		else
		{
			int d = (dx << 1) - dy;
			int d1 = dx << 1;
			int d2 = (dx - dy) << 1;
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
			for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
			{
				if ( d >0)
				{
					d += d2;
					x += sx;
				}
				else
					d += d1;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			}
		}

}
int		move_mouse(int x, int y, t_init *init)
{
	int button = (int)init->button;

	if (button == 1)
	{
		init->coords[0] = x;
		init->coords[1] = y;
		init->coords[4] = 1;
	}
	else if (button == 2)
	{
		init->coords[2] = x;
		init->coords[3] = y;
		init->coords[4] = 0;
	}
	mlx_clear_window(init->mlx_ptr, init->win_ptr);
	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(button));
	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 270, 0x00FA0C1D, ft_itoa(x));
	mlx_string_put(init->mlx_ptr, init->win_ptr, 300, 270, 0x00FA0C1D, ft_itoa(y));
	line(200, 200, 200, 300, 0x00FA0C1D);
	draw_map(init);
	line(init->coords[0], init->coords[1], init->coords[2], init->coords[3], 0x00FA0C1D);
	return (0);
}
int		deal_key(int button, int x, int y, t_init *init)
{
	int i;
	long color;
	char p[2];


	if (button == 1)
	{
		init->coords[0] = x;
		init->coords[1] = y;
		init->coords[4] = 1;
		init->button = 1;
	}
	else if (button == 2)
	{
		init->coords[2] = x;
		init->coords[3] = y;
		init->coords[4] = 0;
		init->button = 2;
	}
	mlx_clear_window(init->mlx_ptr, init->win_ptr);
	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(button));
	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 270, 0x00FA0C1D, ft_itoa(x));
	mlx_string_put(init->mlx_ptr, init->win_ptr, 300, 270, 0x00FA0C1D, ft_itoa(y));
	line(200, 200, 200, 300, 0x00FA0C1D);
	draw_map(init);
	clock_t t = clock();
	line(init->coords[0], init->coords[1], init->coords[2], init->coords[3], 0x00FA0C1D);

	t = clock() - t;
//	if (key == 51)
//	{y
//		mlx_clear_window(mlx_ptr, win_ptr);
//		return (0);
//	}
//	i = 0;
//	while (i < 50000)
//	{
//		if (rand() % 2 == 0 || rand() % 2 == 1)
//			color = 0x00000000;
//		else
//			color = 0x00454545;
//		mlx_pixel_put(mlx_ptr, win_ptr, rand() % 1920, rand() % 1280, color);
//		i++;
//	}


	return 0;
}

int		key_realise(int button, int x, int y, t_init *init)
{
//	int i;
//	long color;
//	char p[2];
//
		init->button = 0;
		return (0);
//	if (button == 1) {
//		coords[0] = x;
//		coords[1] = y;
//		coords[4] = 1;
//	} else if (button == 2) {
//		coords[2] = x;
//		coords[3] = y;
//		coords[4] = 0;
//	}
//	mlx_clear_window(mlx_ptr, win_ptr);
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(button));
//	mlx_string_put(mlx_ptr, win_ptr, 250, 270, 0x00FA0C1D, ft_itoa(x));
//	mlx_string_put(mlx_ptr, win_ptr, 300, 270, 0x00FA0C1D, ft_itoa(y));
//	line(200, 200, 200, 300, 0x00FA0C1D);
//	clock_t t = clock();
//	line(coords[0], coords[1], coords[2], coords[3], 0x00FA0C1D);
//	mlx_hook(win_ptr, 6, (1L << 17), move_mouse, (void *) button);
//	return (0);
}

int count_width(char *line)
{
	int	width;

	width = 0;
	while (*line)
	{
		if (*line == ' ')
			line++;
		else if (*line <= '9' && *line >= '0')
		{
			width++;
			while (*line <= '9' && *line >= '0')
				line++;
		}
		else
			return (0);
	}
	return (width);
}

int	*atoi_line(char *line, int width)
{
	int *int_line;
	int i;

	i = 0;
	if(!(int_line = (int *)malloc(sizeof(int) * width)))
		return (0);
	while (*line)
	{
		if (*line <= '9' && *line >= '0')
		{
			int_line[i] = ft_atoi(line);
			i++;
			while (*line <= '9' && *line >= '0')
				line++;
		}
		line++;
	}
	return (int_line);
}

t_map	*fill_map(char *line, t_map *map)
{
	void	*tmp;

	tmp = (void *)map->map;
	if (!(map->map = (int**)malloc(sizeof(int *) * (map->height + 1))))
		return (0);
	ft_memcpy(map->map, tmp, sizeof(int *) * map->height);
	if (map->width != count_width(line))
		return(0);
	(map->map)[map->height++] = atoi_line(line, map->width);
	free(tmp);
	free(line);
	return (map);
}

t_map	*malloc_map(int fd)
{
	t_map	*map;
	char 	*line;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	if ((get_next_line(fd, &line) <= 0))
		return (0);
	if (!(map->width = count_width(line)))
		return (0);
	if (!(map->map = (int**)malloc(sizeof(int *))))
		return (0);
	*(map->map) = atoi_line(line, map->width);
	map->height = 1;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(fill_map(line, map)))
			return (0);
	}
	return (map);

}

t_init	*malloc_init(int fd)
{
	t_init	*init;

	if (!(init = (t_init*)malloc(sizeof(t_init))))
		return (0);
	init->mlx_ptr = mlx_init();
	init->win_ptr = mlx_new_window(init->mlx_ptr, 1920, 1280, "mlx");
	init->coords[0] = 0;
	init->coords[1] = 0;
	init->coords[2] = 0;
	init->coords[3] = 0;
	init->coords[4] = 0;
	init->button = 0;
	init->s_map = malloc_map(fd);
	return (init);

}

int main(int ac, char **av) {

	t_init *init;
	int fd;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1920, 1280, "mlx");
//	if (ac != 2)
//		exit(1);
	fd = open("42.fdf", O_RDONLY);
	if (fd < 0)
		exit(1);
	if (!(init = malloc_init(fd)))
		exit(1);
	mlx_ptr = init->mlx_ptr;
	win_ptr = init->win_ptr;
    mlx_pixel_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D);
	mlx_hook(init->win_ptr, 4, (1L << 17), deal_key, init);
	mlx_hook(init->win_ptr, 5, (1L << 17), key_realise, init);
	mlx_hook(win_ptr, 6, (1L << 17), move_mouse, init);
    mlx_loop(mlx_ptr);
    printf("Hello, World!\n");

    return 0;
}