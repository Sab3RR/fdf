//
// Created by Vadim SUSOL on 2019-02-01.
//

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <mlx.h>
# include <time.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>

typedef struct	s_map
{
	int			**map;
	int 		width;
	int 		height;
	int 		scale;
}				t_map;
typedef struct	s_coords
{
	int 		x;
	int 		y;
	int 		z;
}				t_coords;

typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	char 		button;
	t_map		*s_map;
	int 		k;
	int 		n_y;
	int 		n_x;
	double 		rad_x;
	double 		rad_y;
	double 		rad_z;
	int 		last_x;
	int 		last_y;
	t_coords	***coords;
	int 		coord[4];
}				t_init;
#endif //FDF_FDF_H
