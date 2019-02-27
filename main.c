#include "fdf.h"

void *mlx_ptr;
void *win_ptr;
int coords[5] = {0, 0, 0, 0, 0};

//void	draw_line(int x, int y, int ex, int ey)
//{
//
//}

//void	draw_map(t_init *init)
//{
//	int i;
//	int j;
//	int width = 0;
//	int height = 0;
//	char	*str;
//
//	i = 0;
//	while (i < init->s_map->height)
//	{
//		j = 0;
//		width = 0;
//		while (j < init->s_map->width)
//		{
//			str = ft_itoa((init->s_map->map)[i][j]);
//			mlx_string_put(init->mlx_ptr, init->win_ptr, width, height, 0x00FA0C1D, str);
//			free(str);
//			width += 40;
//			j++;
//		}
//		height += 40;
//		i++;
//	}
//}

void	fill_coords(t_init *init)
{
	int x;
	int y;
	double s_y;
	double s_x;
	int xx;
	int yy;
	int zz;

	s_y = (double)(init->s_map->height - 1)/2;
	s_x = (double)(init->s_map->width - 1)/2;
	y = 0;
//	init->coord[0] = init->n_x + (int)(s_x * init->k);
//	init->coord[1] = init->n_y;
//	init->coord[2] = init->n_x + (int)(s_x * init->k);
//	init->coord[3] = init->n_y + (init->s_map->height - 1) * init->k;

	init->coord[0] = init->n_x;
	init->coord[1] = init->n_y + (int)(s_y * init->k);
	init->coord[2] = init->n_x + (init->s_map->width - 1) * init->k;
	init->coord[3] = init->n_y + (int)(s_y * init->k);

	while (y < init->s_map->height)
	{
		x = 0;
		while (x < init->s_map->width)
		{
			init->coords[y][x]->x = (init->s_map->width - 1) * init->k / 2 - ((init->s_map->width - 1) * init->k - x * init->k);
			init->coords[y][x]->y = (init->s_map->height - 1) * init->k /2 - y * init->k;
			init->coords[y][x]->z = init->s_map->map[y][x] * 5;
		//	init->coords[y][x]->x = init->coords[y][x]->x;
			xx = init->coords[y][x]->x;
			yy = init->coords[y][x]->y;
			zz = init->coords[y][x]->z;
			init->coords[y][x]->y = (int)(yy * cos(init->rad_y) + zz * sin(init->rad_y));
			init->coords[y][x]->z = (int)(-(yy) * sin(init->rad_y) + zz * cos(init->rad_y));
			yy = init->coords[y][x]->y;
			zz = init->coords[y][x]->z;
			init->coords[y][x]->x = (int)(xx * cos(init->rad_x) + zz * sin(init->rad_x));
			init->coords[y][x]->z = (int)(-(xx) * sin(init->rad_x) + zz * cos(init->rad_x));
			xx = init->coords[y][x]->x;
			zz = init->coords[y][x]->z;
			init->coords[y][x]->x = (int)(xx * cos(init->rad_z) + yy * sin(init->rad_z));
			init->coords[y][x]->y = (int)(-(xx) * sin(init->rad_z) + yy * cos(init->rad_z));
			x++;
		}
		y++;
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

void	normalization(t_init *init)
{
	int map_x;
	int map_y;
//	int x;
//	int	y;

	map_x = (int)(init->k * (init->s_map->width - 1));
	init->n_x = (1920 - map_x)/2;
	map_y = (int)(init->k * (init->s_map->height - 1));
	init->n_y = (1080 - map_y)/2;
	if (init->coords == NULL)
		return ;
//	y = 0;
//	while (y < init->s_map->height)
//	{
//		x = 0;
//		while (x < init->s_map->width)
//		{
//			init->coords[y][x]->x = init->coords[y][x]->x;
//			init->coords[y][x]->y = (int)(init->coords[y][x]->y * cos(init->rad_x) + init->coords[y][x]->z * sin(init->rad_x));
//			init->coords[y][x]->z = (int)(-(init->coords[y][x]->y) * sin(init->rad_x) + init->coords[y][x]->z * cos(init->rad_x));
//			init->coords[y][x]->x = (int)(init->coords[y][x]->x * cos(init->rad_y) + init->coords[y][x]->z * sin(init->rad_y));
//			init->coords[y][x]->z = (int)(-(init->coords[y][x]->x) * sin(init->rad_y) + init->coords[y][x]->z * cos(init->rad_y));
//			x++;
//		}
//		y++;
//	}
	}

void	k_init(t_init *init)
{
	init->k = init->s_map->scale;
}

void	draw_green_map(t_init *init)
{
	int	x;
	int y;
	int c[2];

	c[0] = (init->s_map->width - 1) * init->k / 2;
	c[1] = (init->s_map->height - 1) * init->k / 2;
	y = 0;
	while (y < init->s_map->height)
	{
		x = 0;
		while (x < init->s_map->width)
		{
			if (x == 0 && y == 0)
			{
				x++;
				continue;
			}
			else if (y == 0 && x > 0)
			{
				line(init->n_x + c[0] + init->coords[y][x]->x, init->n_y + c[1] - init->coords[y][x]->y, init->n_x + c[0] + init->coords[y][x - 1]->x, init->n_y + c[1] - init->coords[y][x - 1]->y, 0x00D800);
			}
			else if (y != 0 && x != 0)
			{
				line(init->n_x + c[0] + init->coords[y][x]->x, init->n_y + c[1] - init->coords[y][x]->y, init->n_x + c[0] + init->coords[y][x - 1]->x, init->n_y + c[1] - init->coords[y][x - 1]->y, 0x00D800);
				line(init->n_x + c[0] + init->coords[y][x]->x, init->n_y + c[1] - init->coords[y][x]->y, init->n_x + c[0] + init->coords[y - 1][x]->x, init->n_y + c[1] - init->coords[y - 1][x]->y, 0x00D800);
			}
			else if (y != 0 && x == 0)
			{
				line(init->n_x + c[0] + init->coords[y][x]->x, init->n_y + c[1] - init->coords[y][x]->y, init->n_x + c[0] + init->coords[y - 1][x]->x, init->n_y + c[1] - init->coords[y - 1][x]->y, 0x00D800);
			}
			x++;
		}
		y++;
	}

}

void	draw_map(t_init *init)
{
	int i;
	int	j;

	i = 0;
	while (i < init->s_map->height)
	{
		j = 0;
		while (j < init->s_map->width)
		{
			if (i == 0 && j == 0)
			{
				j++;
				continue ;
			}

			else if (i == 0 && j > 0)
			{
				line((int)((j * init->k) * cos(init->rad_x) + init->n_x), (int)((i * init->k) * cos(init->rad_y) + init->n_y), (int)(((j - 1) * init->k) * cos(init->rad_x) + init->n_x), (int)((i * init->k) * cos(init->rad_y) + init->n_y), 0x00FA0C1D);
			}
			else if (i != 0 && j != 0)
			{
				line((int)((j * init->k) * cos(init->rad_x) + init->n_x), (int)((i * init->k) * cos(init->rad_y) + init->n_y), (int)(((j - 1) * init->k) * cos(init->rad_x) + init->n_x), (int)((i * init->k) * cos(init->rad_y) + init->n_y), 0x00FA0C1D);
				line((int)((j * init->k) * cos(init->rad_x) + init->n_x), (int)((i * init->k) * cos(init->rad_y) + init->n_y), (int)((j * init->k) * cos(init->rad_x) + init->n_x), (int)(((i - 1) * init->k) * cos(init->rad_y) + init->n_y), 0x00FA0C1D);
			}
			else if (i != 0 && j == 0)
			{
				line((j * init->k) + init->n_x, (int)((i * init->k) * cos(init->rad_y) + init->n_y), (j * init->k) + init->n_x, (int)(((i - 1) * init->k) * cos(init->rad_y) + init->n_y), 0x00FA0C1D);
			}
			j++;
		}
		i++;
	}
}

int		move_mouse(int x, int y, t_init *init)
{
	int button = (int)init->button;

	if (button == 1)
	{
		if (init->last_y != -1)
		{
			if (init->rad_y > 6.28319)
				init->rad_y = init->rad_y - 6.28319;
			if (init->rad_y < -6.28319)
				init->rad_y = init->rad_y + 6.28319;
			init->rad_y -= (y - init->last_y) * 0.0014544 * 4;
			init->last_y = y;
//			init->rad_y = (y - init->last_y) * 0.0014544 * 4;
//			init->last_y = y;
		}
		else
		{
			init->last_y = y;
		}
		if (init->last_x != -1)
		{
			if (init->rad_x > 6.28319)
				init->rad_x = init->rad_x - 6.28319;
			if (init->rad_x < 0)
				init->rad_x = init->rad_x + 6.28319;
			init->rad_x += (x - init->last_x) * 0.0014544 * 4;
			init->last_x = x;
//			init->rad_x = (x - init->last_x) * 0.0014544 * 4;
//			init->last_x = x;
		}
		else
		{
			init->last_x = x;
		}
		normalization(init);
	}
	else
	{
		init->last_y = -1;
		init->last_x = -1;
	}
	mlx_clear_window(init->mlx_ptr, init->win_ptr);
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(button));
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 270, 0x00FA0C1D, ft_itoa(x));
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 300, 270, 0x00FA0C1D, ft_itoa(y));
//	line(200, 200, 200, 300, 0x00FA0C1D);
	//draw_map(init);
	fill_coords(init);
//	line(init->coord[0], init->coord[1], init->coord[2], init->coord[3], 0x00Dfff);
	draw_green_map(init);
//	system("clear");
//	printf("%f\n", init->rad_x);
//	printf("%f\n", init->rad_y);
	return (0);
}
int		deal_key(int button, int x, int y, t_init *init)
{
	int i;
	long color;
	char p[2];


	if (button == 1)
	{
		init->button = 1;
	}
	else if (button == 2)
	{
		init->button = 2;
	}
	else if (button == 4)
	{
		init->s_map->scale += 1;
		k_init(init);
		normalization(init);
	}
	else if (button == 5)
	{
		if (init->s_map->scale > 1)
		{
			init->s_map->scale -= 1;
			k_init(init);
			normalization(init);
		}
	}
	mlx_clear_window(init->mlx_ptr, init->win_ptr);
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D, ft_itoa(button));
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 270, 0x00FA0C1D, ft_itoa(x));
//	mlx_string_put(init->mlx_ptr, init->win_ptr, 300, 270, 0x00FA0C1D, ft_itoa(y));
//	line(200, 200, 200, 300, 0x00FA0C1D);
	//draw_map(init);
	fill_coords(init);
	//line(init->coord[0], init->coord[1], init->coord[2], init->coord[3], 0x00D800);
	draw_green_map(init);
	clock_t t = clock();


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
		else if ((*line <= '9' && *line >= '0') || *line == '-')
		{
			width++;
			line++;
			if (*line == '-')
				return (0);
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
		if ((*line <= '9' && *line >= '0') || *line == '-')
		{
			int_line[i] = ft_atoi(line);
			i++;
			while ((*line <= '9' && *line >= '0') || *line == '-')
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

	map = (t_map*)malloc(sizeof(t_map));
	if ((get_next_line(fd, &line) <= 0))
		return (0);
	map->width = count_width(line);
	map->map = (int**)malloc(sizeof(int *));
	*(map->map) = atoi_line(line, map->width);
	map->height = 1;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(fill_map(line, map)))
			return (0);
	}
	free(line);
	return (map);

}



t_coords	***malloc_coords(t_init *init)
{
	t_coords	***coords;
	int 		i;
	int 		j;

	coords = (t_coords***)malloc(sizeof(t_coords**) * (init->s_map->height));

	i = 0;
	while (i < init->s_map->height)
	{
		coords[i] = (t_coords**)malloc(sizeof(t_coords*) * init->s_map->width);
		j = 0;
		while (j < init->s_map->width)
		{
			coords[i][j] = (t_coords*)malloc(sizeof(t_coords));
			coords[i][j]->z = 0;
			coords[i][j]->x = 0;
			coords[i][j]->y = 0;
			j++;
		}
		i++;

	}
	return (coords);
}

t_init	*malloc_init(int fd)
{
	t_init	*init;

	if (!(init = (t_init*)malloc(sizeof(t_init))))
		return (0);
	init->mlx_ptr = mlx_init();
	init->win_ptr = mlx_new_window(init->mlx_ptr, 1920, 1080, "mlx");
	init->last_x = -1;
	init->last_y = -1;
	init->s_map = malloc_map(fd);
	init->coords = malloc_coords(init);
	init->s_map->scale = 1;
	init->rad_x = 0;
	init->rad_y = 0;
	init->rad_z = 0;
	init->coord[0] = 0;
	init->coord[1] = 0;
	init->coord[2] = 0;
	init->coord[3] = 0;
	k_init(init);
	normalization(init);
	fill_coords(init);
	return (init);

}

int	key_press(int kc, t_init *init)
{
	if (kc == 126)
	{
		init->s_map->scale *= 2;
	}
	else if (kc == 125)
	{
		if (init->s_map->scale > 1)
			init->s_map->scale /= 2;
	}
	else if (kc == 82)
	{
		init->rad_x = 0;
		init->rad_y = 0;
		init->rad_z = 0;
	}
	else if (kc == 83)
	{
		init->rad_x = 1.5708;
		init->rad_y = 0;
		init->rad_z = 0;
 	}
	else if (kc == 84)
	{
		init->rad_x = 0;
		init->rad_y = 1.5708;
		init->rad_z = 0;
	}
	k_init(init);
	normalization(init);
	mlx_clear_window(init->mlx_ptr, init->win_ptr);
	fill_coords(init);
	draw_green_map(init);
	return (0);
}

int 	loop_hook(t_init *init)
{
//	char *str;
//	clock_t t;
//
//	if (init->t == 0)
//		init->t = clock();
//	t = clock();
//	mlx_clear_window(init->mlx_ptr, init->win_ptr);
//	if (t - init->t > CLOCKS_PER_SEC)
//	{
//		str = ft_itoa(init->cadr);
//		mlx_string_put(init->mlx_ptr, init->win_ptr, 250, 250, 0x00FA0C1D, str);
//		init->t = clock();
//		free(str);
//	}
//	k_init(init);
//	normalization(init);
//	fill_coords(init);
//	draw_green_map(init);
//	init->cadr += 1;
	return (0);

}

int main(int ac, char **av) {

	t_init *init;
	int fd;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1920, 1280, "mlx");
//	if (ac != 2)
//		exit(1);
	fd = open("20-60.fdf", O_RDONLY);
	if (fd < 0)
		exit(1);
	if (!(init = malloc_init(fd)))
		exit(1);
	mlx_ptr = init->mlx_ptr;
	win_ptr = init->win_ptr;
	mlx_hook(init->win_ptr, 4, (1L << 17), deal_key, (void*)init);
	mlx_hook(init->win_ptr, 5, (1L << 17), key_realise, (void*)init);
	mlx_hook(win_ptr, 6, (1L << 17), move_mouse, (void*)init);
	mlx_hook(win_ptr, 2, (1L << 17), key_press, (void*)init);
	mlx_loop_hook(win_ptr, loop_hook, (void*)init);
    mlx_loop(mlx_ptr);
    printf("Hello, World!\n");

    return 0;
}