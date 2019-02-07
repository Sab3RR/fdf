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
}				t_map;

typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			coords[5];
	char 		button;
	t_map		*s_map;

}				t_init;
#endif //FDF_FDF_H
