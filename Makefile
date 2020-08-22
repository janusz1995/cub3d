
.PHONY: all re fclean clean bonus

NAME = cub3d

SRC = cub3d.c quarters.c draw.c min_length.c find_vertical.c find_horizontal.c sort_by_len_list.c \
		check_direction_player.c check_player_sight.c clear_flags.c fill_struct.c find_sprites.c \
		draw_pixel_sprite.c new_sprite.c add_back_sprite.c draw_sprite.c my_mlx_pixel_put.c \
		flood_fill.c get_textures.c errors.c check_line.c free_double_arr.c check_num_lines.c \


SRCO = $(SRC:.c=.o)

CC = gcc

LIBFT = $(LIBFTDIR)libft.a 

LIBFTDIR = ./libft/

HEADER = cub3d.h

FLAGS = -Wall -Werror -Wextra  -g

all: $(NAME)

$(NAME): $(SRCO) $(LIBFT)
	$(CC) -L./mlx -framework OpenGL -framework AppKit -lmlx -L$(LIBFTDIR) -lft $(SRCO) -o $(NAME)

$(LIBFT):
		make -C $(LIBFTDIR)

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -I ./mlx.h -c $< -o $@

clean:
	rm -f $(SRCO)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all


