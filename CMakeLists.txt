cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -I mlx -L../mlx -lmlx")

include_directories(.)
include_directories(libft)

add_executable(cub3d
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_calloc.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd_back.c
        libft/ft_lstadd_front.c
        libft/ft_lstclear.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstlast.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstsize.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmapi.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strtrim.c
        libft/ft_substr.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/get_next_line_utils.c
        libft/libft.h
        check_direction_player.c
        check_player_sight.c
        clear_flags.c
        cub3d.c
        cub3d.h
        draw.c
        fill_struct.c
        find_horizontal.c
        find_vertical.c
        min_length.c
        quarters.c
        sort_by_len_list.c
        fill_struct.c
        find_sprites.c
        draw_pixel_sprite.c
        new_sprite.c
        add_back_sprite.c
        draw_sprite.c
        my_mlx_pixel_put.c
        flood_fill.c
        check_num_lines.c
        free_double_arr.c
        check_line.c
        errors.c
        get_textures.c
        )

