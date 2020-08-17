


#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# define M_PI_6 M_PI_2/3
# define M_PI_3 M_PI/3

# include "math.h"
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_sprites
{
	int					x;
	int					y;
	double 				len;
	struct s_sprites	*next;
}					t_sprites;

typedef struct  s_flags {

	int 		north;
	int 		south;
	int 		east;
	int 		west;
	int 		horz;
	int 		vert;
}               t_flags;

typedef struct  s_player {

	double 		x;
	double 		y;
	double		angle;
	double 		ang_start;
	double 		ang_end;
	double 		ang_fov;

}               t_player;

typedef struct  s_textures {

	void 		*txt;
	int 		height;
	int 		width;
	int			*addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_textures;

typedef struct  s_calc {

	double 		min_len;
	double 		dis_to_proj;
	double		dis_x;
    double		dis_y;
	double		dis;
	double 		x_or_y;
	double 		*arr_min_len_wall;
	int 		sprite_x;
	int 		sprite_y;
	double		sprite_dir;
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
	int 		vert;
	int 		horz;
	double		vert_x;
	double		vert_y;
	double		horz_x;
	double		horz_y;
	int			color;
	int 		speed;
	int 		cube_size;
	t_player 	player;
	t_calc		calc;
	t_textures	txt1;
	t_textures	txt2;
	t_textures	txt3;
	t_textures	txt4;
	t_textures	sprite;
	t_flags		flag;
	t_sprites 	*sprites;
}               t_data;

void 		clear_flags(t_data *img);
void 		draw_wall(t_data *img);
void		draw_map2d(t_data *img);
void    	quarters_horz(t_data *img);
void    	quarters_vert(t_data *img);
void 		draw_map_player(t_data *img);
void 		draw_floor(t_data *img, int obj_start);
void 		draw_sky(t_data *img, int obj_start);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		check_player_sight(t_data *img);
void 		swap_two_sprites(t_sprites **head, t_sprites *one, t_sprites *two);
void 		sort_len_list(t_data *img);

double 		min_length(double horz, double vert, t_data *img);
double 		find_vertical(t_data *img);
double		find_horizontal(t_data *img);

int			lst_size(t_sprites *lst);
int 		check_direction_player(int sym, t_data *img);

t_sprites 	last_sprite(t_sprites *lst);

#endif
