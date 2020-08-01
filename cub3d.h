


#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# define M_PI_6 M_PI_2/3

# include "math.h"

typedef struct  s_player {

	double 		x;
	double 		y;
	double		angle;
	double 		ang_start;
	double 		ang_end;
	double 		ang_fov;

}               t_player;

typedef struct  s_calc {

	double 		min_len;
	double 		dis_to_proj;
}               t_calc;

typedef struct  s_data {

	void        *img;
	char		**map;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	void 		*mlx;
	void 		*mlx_win;
	double 		x;
	double 		y;
	double 		width;
	double 		height;
	int 		pixel;
	int			vert;
	int			horz;
	int			color;
	int 		speed;
	int 		cube_size;
	t_player 	player;
	t_calc		calc;
}               t_data;

void 	draw_wall(t_data *img);
void	draw_map2d(t_data *img);
void    quarters_horz(t_data *img);

#endif
