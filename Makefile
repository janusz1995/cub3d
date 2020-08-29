
.PHONY: all re fclean clean

NAME = cub3D

SRC = cub3d.c quarters.c draw.c min_length.c find_vertical.c find_horizontal.c sort_by_len_list.c \
		check_direction_player.c check_player_sight.c clear_flags.c fill_struct.c find_sprites.c \
		draw_pixel_sprite.c new_sprite.c add_back_sprite.c draw_sprite.c my_mlx_pixel_put.c \
		flood_fill.c get_textures.c errors.c check_line.c free_double_arr.c check_num_lines.c \
		bmp.c keycode.c check_max_and_min_screensize.c split_lines.c const_param.c all_free.c \
		parse_line.c check_str.c check_argv.c move_sprite_in_list.c screenshot.c x_and_y_max.c \
		sprite_collision.c valid_map.c close_window.c read_file.c

SRCO = $(SRC:.c=.o)

CC = gcc

LIBFT = $(LIBFTDIR)libft.a

MLX = $(MLXDIR)libmlx.dylib

MLXDIR = ./mlx/

LIBFTDIR = ./libft/

HEADER = cub3d.h

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(SRCO) $(LIBFT) $(MLX)
	$(CC) -L./mlx -framework OpenGL -framework AppKit -lmlx -L$(LIBFTDIR) -lft $(SRCO) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)
	cp $(MLXDIR)libmlx.dylib ./

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -I ./mlx.h -c $< -o $@

clean:
	rm -f $(SRCO)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	rm -f $(MLXDIR)libmlx.dylib
	make fclean -C $(LIBFTDIR)

re: fclean all
