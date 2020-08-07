


#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# define M_PI_6 M_PI_2/3
# define M_PI_3 M_PI/3

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
	double		dis_x;
    double		dis_y;
	double		dis;
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
	int 		width;
	int 		height;
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
void    quarters_vert(t_data *img);
void 	draw_map_player(t_data *img);
void 	draw_floor(t_data *img, int obj_start);
void 	draw_sky(t_data *img, int obj_start);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
