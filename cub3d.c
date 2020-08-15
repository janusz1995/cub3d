

#include <stdio.h>
#include "mlx.h"
#include "cub3d.h"
#include <fcntl.h>
#include "libft/get_next_line.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	add_back_sprite(t_sprites **lst, t_sprites *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = new;
	}
}

void	add_front_sprite(t_sprites **lst, t_sprites *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_sprites 	*lstnew(int y, int x, int cube_size)
{
	t_sprites 	*list;

	list = (t_sprites*)malloc(sizeof(t_sprites));
	if (!list)
		return (NULL);
	list->x = x + cube_size / 2;
	list->y = y + cube_size / 2;
	list->len = 0;
	list->next = NULL;
//	write(1, "\n",1);
//	ft_putnbr_fd(list->x, 1);
//	write(1, "\n",1);
//	ft_putnbr_fd(list->y, 1);
//	write(1, "\n",1);
	return (list);
}

void	find_sprites(t_data *img)
{
	int 		i;
	int 		j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == '2')
				add_back_sprite(&img->sprites, (lstnew((i * img->cube_size), (j * img->cube_size), img->cube_size)));
			j++;
		}
		i++;
	}
}


void 	draw_sprite(t_data *img)
{
	int 	sprite_h;
//	int 	x;
//	int 	y;
	double 	sprite_x;
	int 	sprite_y;
	double sprite_dir;

	img->sprites->len = sqrt(pow(img->sprites->x - img->player.x, 2) + pow(img->sprites->y - img->player.y, 2));
	//img->sprites->len = sqrt(img->sprites->len);
	sprite_h = (int)((img->calc.dis_to_proj / (img->sprites->len * img->cube_size)) * img->height);

	sprite_dir = atan2((img->sprites->y - img->player.y), (img->sprites->x - img->player.x));

//	if (x < 0 && y < 0)
//		sprite_dir += M_PI;
//	else if (x > 0 && y < 0)
//		sprite_dir += (M_PI_2 + M_PI);
//	else if (x < 0 && y > 0)
//		sprite_dir += M_PI_2;

	while (sprite_dir - img->player.angle >  M_PI)
		sprite_dir -= 2*M_PI;
	while (sprite_dir - img->player.angle < -M_PI)
		sprite_dir += 2*M_PI;

	sprite_dir = sprite_dir - img->player.angle;
	//printf("%f\n", sprite_dir);
	sprite_x = sprite_dir * (img->width/2) / (M_PI / 6) + img->width/2 - sprite_h/2;
	sprite_y = img->height/2 - sprite_h/2;
	int i = 0;
	int j = 0;
	//if (sprite_dir < img->player.ang_end && sprite_dir > img->player.ang_end - M_PI_6)
		while (i < sprite_h)
		{
			j = 0;
			while (j < sprite_h)
			{
				if (sprite_x + i < img->width && i + sprite_x >= 0 && img->calc.arr_min_len_wall[(int)(sprite_x + i)] > img->sprites->len)
					my_mlx_pixel_put(img, sprite_x + i, sprite_y + j, 0x000000);
				j++;
			}

			i++;
		}
}

/// Split 2 lines and \n

char *split_lines(char *line, char *list)
{
	char *tmp;

	tmp = list;
	if (!(list = ft_strjoin(list, line)))
		return (NULL);
	free(tmp);
	tmp = list;
	if (!(list = ft_strjoin(list, "\n")))
		return (NULL);
	free(tmp);
	free(line);
	return (list);
}

char	**parse_map()
{
	int fd;
	char *line;
	char *list;
	char **map;
	//int count = 0;

	if (!(fd = open("map.txt", O_RDONLY)))
		printf("%d", fd); // !!!!!!!!!!!! need fix return (need return NULL!)
	list = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		if (!(list = split_lines(line, list)))
			return (NULL);
	}
	if (!(list = split_lines(line, list)))
		return (NULL);
	close(fd);
	map = ft_split(list, '\n');

	//while (ft_strchr(map[count], 'N'))
		//count++;
	return (map);
	//draw_map2d(map, img);
	//count = ft_strlen(list);
	//printf("%d", count);
}

int 	check_direction_player(int sym, t_data *img)
{
	if (sym == 'N' || sym == 'S' || sym == 'W' || sym == 'E')
	{
		img->player.ang_fov = M_PI / 3;
		if (sym == 'E')
			img->player.angle = 0; //  0/360
		else if (sym == 'S')
			img->player.angle = M_PI_2; // 90
		else if (sym == 'W')
			img->player.angle = M_PI; // 180
		else
			img->player.angle = M_PI_2 * 3; // 270
		return (1);
	}
	else
		return (0);
}

void	check_player_sight(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (check_direction_player(img->map[i][j], img))
			{
				img->vert = j;
				img->horz = i;
				img->player.x = (j * img->cube_size) + (img->cube_size/2);
				img->player.y = (i * img->cube_size) + (img->cube_size/2);
				break ;
			}
			j++;
		}
		i++;
	}
}

void 	tracer(t_data *img)
{
	double horz_len;
	double vert_len;
	//int i = 0;

	horz_len = find_horizontal(img);
	vert_len = find_vertical(img);

	img->calc.min_len = min_length(horz_len, vert_len, img);
	img->calc.arr_min_len_wall[img->pixel] = img->calc.min_len;
	img->calc.min_len = img->calc.min_len * cos(img->player.angle - img->player.ang_start);

//	if (img->calc.min_len != INFINITY)
//	{
//		while(i < img->calc.min_len)
//		{
//			my_mlx_pixel_put(img, (int)(img->player.x + i * cos(img->player.ang_start)), (int)(img->player.y + i * sin(img->player.ang_start)), 0x00FFFFFF);
//			i++;
//		}
//	}
	draw_wall(img);
	//if (img->calc.min_len > img->sprites->len)
		//draw_sprite(img);
	clear_flags(img);
}

void 	func(t_data *img)
{
	int			count;
	double		ang_step;
	t_sprites 	*head;
	count = 0;

	img->img = mlx_new_image(img->mlx, img->width , img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length , &img->endian);

	ang_step = M_PI_3 / img->width;
	img->player.ang_start = img->player.angle - M_PI_6; // угол начала
	img->player.ang_end = img->player.angle + M_PI_6; // угол конца
	//draw_map_player(img);
	while (count < img->width)
	{
		img->player.ang_start > 2*M_PI ? img->player.ang_start -= 2*M_PI : 0;
		img->player.ang_start < 0 ? img->player.ang_start += 2*M_PI : 0;
		img->pixel = count; // координата столба по X
		tracer(img);
		img->player.ang_start += ang_step;
		count++;
	}
	head = img->sprites;
	while (img->sprites != NULL)
	{
		draw_sprite(img);
		img->sprites = img->sprites->next;
	}
	img->sprites = head;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

/// Draw 32 pixels

//void 	draw_cub32(int x, int y, int c, t_data *img)
//{
//	int x_max, y_max, color , x_img;
//	x_max = x + 32;
//	y_max = y + 32;
//	x_img = x;
//	//write(1, "fail\n", 5);
//	if (c == '0')
//		color = 0x00FF0000; // color - red
//	else if (c == '1')
//		color = 0x000000FF; // color - blue
//	while (y < y_max)
//	{
//		x = x_img;
//		while (x < x_max)
//			my_mlx_pixel_put(img, x++, y, color);
//		y++;
//	}
//}

//void 	draw_player(int x_max, int y_max, t_data *img)
//{
//	int count_y, count_x;
//
//	count_x = img->player.x;
//
//	while (count_x++ < x_max)
//	{
//		count_y = img->player.y;
//		while (count_y++ < y_max)
//			my_mlx_pixel_put(img, count_x, count_y, img->color);
//	}
//}
//
//void 	draw_map_player(t_data *img)
//{
//	draw_map2d(img);
//	draw_player(img->player.x + 1, img->player.y + 1, img);
//}

/// Draw map top view

//void	draw_map2d(t_data *img)
//{
//	int count_y, count_x, i, j;
//
//	count_y = 0;
//	i = 0;
//
//	while (img->map[i])
//	{
//		j = 0;
//		count_x = 0;
//		while (img->map[i][j])
//		{
//			if(img->map[i][j] == '1' || img->map[i][j] == '0')
//				draw_cub32(count_x, count_y, img->map[i][j], img);
//			j++;
//			count_x += 32;
//		}
//		count_y += 32;
//		i++;
//	}
//}

int 	key(int keycode, t_data *img) 
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 126) // up
	{
		if (img->map[(unsigned int)(img->player.y + 5 * sin(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
			img->player.y += 5 * sin(img->player.angle);
		if (img->map[(unsigned int)img->player.y/img->cube_size][(unsigned int)(img->player.x + 5 * cos(img->player.angle))/img->cube_size] != '1')
			img->player.x += 5 * cos(img->player.angle);
	}
	else if (keycode == 125) // down
	{
		if (img->map[(unsigned int)(img->player.y - 5 * sin(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
			img->player.y -= 5 * sin(img->player.angle);
		if (img->map[(unsigned int)img->player.y/img->cube_size][(unsigned int)(img->player.x - 5 * cos(img->player.angle))/img->cube_size] != '1')
			img->player.x -= 5 * cos(img->player.angle);
	}
	else if (keycode == 124) // right
	{
		img->player.angle += 0.1;
		if (img->player.angle > (M_PI * 2))
			img->player.angle -= M_PI * 2;
	}
	else if (keycode == 123) // left
	{
		img->player.angle -= 0.1;
		if (img->player.angle < 0)
			img->player.angle += M_PI * 2;
	}

	mlx_destroy_image(img->mlx, img->img);
	func(img);
	return (1);
}

int		main()
{

	t_data img;
	img.width = 1920;
	img.height = 1080;
	img.cube_size = 32;
	img.calc.dis_to_proj = (img.width / 2) / tan(M_PI_6); // distance to proection
	//img.player.x = 700;
	//img.player.y = 800;
	//img.color = 0x0000FF00;
	//img.speed = 5;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "Cub3d - drina");

	// textures 1
	img.txt1.txt = mlx_xpm_file_to_image(img.mlx, "textures/WALL97.xpm", &img.txt1.width, &img.txt1.height);
	img.txt1.addr = (int*)mlx_get_data_addr(img.txt1.txt, &img.txt1.bits_per_pixel, &img.txt1.line_length , &img.txt1.endian);

	// textures 2
	img.txt2.txt = mlx_xpm_file_to_image(img.mlx, "textures/WALL65.xpm", &img.txt2.width, &img.txt2.height);
	img.txt2.addr = (int*)mlx_get_data_addr(img.txt2.txt, &img.txt2.bits_per_pixel, &img.txt2.line_length , &img.txt2.endian);

	// textures 3
	img.txt3.txt = mlx_xpm_file_to_image(img.mlx, "textures/WALL75.xpm", &img.txt3.width, &img.txt3.height);
	img.txt3.addr = (int*)mlx_get_data_addr(img.txt3.txt, &img.txt3.bits_per_pixel, &img.txt3.line_length , &img.txt3.endian);

	// textures 4
	img.txt4.txt = mlx_xpm_file_to_image(img.mlx, "textures/WALL76.xpm", &img.txt4.width, &img.txt4.height);
	img.txt4.addr = (int*)mlx_get_data_addr(img.txt4.txt, &img.txt1.bits_per_pixel, &img.txt4.line_length , &img.txt4.endian);

	// sprite
	img.sprite.txt = mlx_xpm_file_to_image(img.mlx, "textures/WALL76.xpm", &img.sprite.width, &img.sprite.height);
	img.sprite.addr = (int*)mlx_get_data_addr(img.sprite.txt, &img.sprite.bits_per_pixel, &img.sprite.line_length , &img.sprite.endian);

	img.calc.arr_min_len_wall = (double*)malloc(img.width * sizeof(double));

	if (!(img.map = parse_map()))
			return (0);
	check_player_sight(&img);
	img.sprites = NULL;
	find_sprites(&img);
	func(&img);
	//draw_map_player(&img);

	mlx_hook(img.mlx_win, 2, 1L, &key, &img);
	mlx_loop(img.mlx);
	return (0);
}


