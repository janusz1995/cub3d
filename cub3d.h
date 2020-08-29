/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:27:10 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:27:12 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# define M_PI_6 M_PI_2/3
# define M_PI_3 M_PI/3

# include "math.h"
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "libft/get_next_line.h"

typedef struct			s_path
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*sprite;
}						t_path;

typedef struct			s_sprites
{
	int					x;
	int					y;
	double				len;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_flags
{
	int					north;
	int					south;
	int					east;
	int					west;
	int					horz;
	int					vert;
	int					width;
	int					height;
	int					sky;
	int					floor;
	int					sprite;
	int					error;
	int					screenshot;
}						t_flags;

typedef	struct			s_errors
{
	int					no_valid_map;
	int					num_players;
	int					textures;
	int					no_valid_color;

}						t_errors;

typedef struct			s_player
{
	double				x;
	double				y;
	double				angle;
	double				ang_start;
	double				ang_end;
	double				ang_fov;
	char				letter;
}						t_player;

typedef struct			s_textures
{

	void				*txt;
	int					height;
	int					width;
	int					*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_textures;

typedef struct			s_calc
{
	double				min_len;
	double				dis_to_proj;
	double				dis_x;
	double				dis_y;
	double				dis;
	double				x_or_y;
	double				*arr_min_len_wall;
	int					sprite_x;
	int					sprite_y;
	double				sprite_dir;
	double				ang_step;
	int					x_max;
	int					y_max;
}						t_calc;

typedef struct			s_data
{
	void				*img;
	char				**map;
	char				**flood_map;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	void				*mlx;
	void				*mlx_win;
	double				x;
	double				y;
	int					width;
	int					height;
	int					pixel;
	int					vert;
	int					horz;
	double				vert_x;
	double				vert_y;
	double				horz_x;
	double				horz_y;
	int					color_floor;
	int					color_sky;
	int					cube_size;
	t_player			player;
	t_calc				calc;
	t_textures			txt1;
	t_textures			txt2;
	t_textures			txt3;
	t_textures			txt4;
	t_textures			sprite;
	t_flags				flag;
	t_sprites			*sprites;
	t_path				path;
	t_errors			error;
}						t_data;

void					clear_flags(t_data *img);
void					draw_wall(t_data *img);
void					quarters_horz(t_data *img);
void					quarters_vert(t_data *img);
void					draw_floor(t_data *img, int obj_start);
void					draw_sky(t_data *img, int obj_start);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					check_player_sight(t_data *img);
void					swap_two_sprites(t_sprites **head, t_sprites *one,
											t_sprites *two);
void					sort_len_list(t_data *img);
void					fill_width_and_height(t_data *img, char *str);
void					fill_side(t_data *img, char *str, char **side,
															int *flag);
void					fill_color(char *str, int *color, t_data *img,
															int *flag);
void					free_double_arr(char **arr);
void					void_flags_struct(t_data *img);
void					find_sprites(t_data *img);
void					add_back_sprite(t_data *img, t_sprites *new);
void					draw_pixel_sprite(t_data *img, t_sprites *tmp,
											double coef, int sprite_h);
void					draw_sprite(t_data *img, t_sprites *tmp);
void					flood_fill(t_data *img, int x, int y, char new_sym);
void					get_textures(t_data *img);
void					errors(t_data *img);
void					func(t_data *img);
void					check_max_and_min_screensize(t_data *img);
void					all_free(t_data *img);
void					const_param(t_data *img);
void					parse_line(t_data *img, char *str);
void					check_str(char *str, t_data *img);
void					check_argv(int argc, char **argv, t_data *img);
void					move_sprite(t_data *img);
void					screenshot(t_data *img);
void					x_and_y_max(t_data *img);
void					sprite_collision(t_data *img);
void					valid_map(char *str, t_data *img);
double					min_length(double horz, double vert, t_data *img);
double					find_vertical(t_data *img);
double					find_horizontal(t_data *img);
int						lst_size(t_sprites *lst);
int						check_direction_player(int sym, t_data *img);
int						check_flags_struct(t_data *img);
int						check_line(char *str);
int						check_num_lines(char **str, int c);
int						get_color(t_data *data, int x, int y);
int						save_screenshot(t_data *img);
int						key(int keycode, t_data *img);
int						sprite_coll_up(t_data *img, char x_or_y,
										t_sprites *head);
int						sprite_coll_down(t_data *img,
										char x_or_y, t_sprites *head);
int						close_window(t_data *img);
char					*split_lines(char *line, char *list);
char					*read_file(t_data *img, int fd, char *list);
t_sprites				*last_sprite(t_data *img);
t_sprites				*lstnew(int y, int x, int cube_size);

#endif
