
.PHONY: all re fclean clean bonus

NAME = cub3d

SRC = cub3d.c quarters.c draw.c min_length.c find_vertical.c find_horizontal.c

SRCO = $(SRC:.c=.o)

CC = gcc

LIBFT = $(LIBFTDIR)libft.a 

LIBFTDIR = ./libft/

HEADER = cub3d.h

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRCO) $(LIBFT)
	$(CC) -L./mlx -framework OpenGL -framework AppKit -lmlx -L$(LIBFTDIR) -lft $(SRCO) -o $(NAME)

$(LIBFT):
		make -C $(LIBFTDIR)

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -I ./mlx.h -c $< -o $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all


