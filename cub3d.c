

#include <stdio.h>
//#include "mlx/mlx.h"
#include "cub3d.h"
//#include <fcntl.h>
//#include "libft/get_next_line.h"


void 		all_len_sprites(t_data *img)
{
	t_sprites *head;

	head = img->sprites;
	while (head != NULL)
	{
		printf("%f\n", head->len);
		head = head->next;
	}
}

void 	parse_line(t_data *img, char *str)
{
	int 	count;

	count = 0;
	if (str[count] == 'R' && str[count + 1] == ' ')
		fill_width_and_height(img, str);
	else if (str[count] == 'W' && str[count + 1] == 'E' && str[count + 2] == ' ')
		fill_side(img, str, &img->path.west, &img->flag.west);
	else if (str[count] == 'N' && str[count + 1] == 'O' && str[count + 2] == ' ')
		fill_side(img, str, &img->path.north, &img->flag.north);
	else if (str[count] == 'S' && str[count + 1] == 'O' && str[count + 2] == ' ')
		fill_side(img, str, &img->path.south, &img->flag.south);
	else if (str[count] == 'E' && str[count + 1] == 'A' && str[count + 2] == ' ')
		fill_side(img, str, &img->path.east, &img->flag.east);
	else if (str[count] == 'S' && str[count + 1] == ' ')
		fill_side(img, str, &img->path.sprite, &img->flag.sprite);
	else if (str[count] == 'F' && str[count + 1] == ' ')
		fill_color(str, img->color_floor, img, &img->flag.floor);
	else if (str[count] == 'C' && str[count + 1] == ' ')
		fill_color(str, img->color_sky, img, &img->flag.sky);
	else
		img->flag.error = 1;

}

void 	check_str(char *str, t_data *img)
{
	int count;

	count = 0;
	while (str[count] == ' ')
		count++;
	if (str[count] == '\n' || str[count] == '\0')
	{
		free(str);
		str = NULL;
	}
	else
		if (ft_isalpha(str[count]))
			parse_line(img, &str[count]);
		else
			img->flag.error = 1;
}

/// Split 2 lines and \n

char 	*split_lines(char *line, char *list)
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
	//if (line != NULL)
		free(line);
	return (list);
}

void		parse(t_data *img)
{
	int fd;
	char *line;
	char *list;

	if (!(fd = open("map.txt", O_RDONLY)))
		printf("%d", fd); // !!!!!!!!!!!! need fix return (need return NULL!)
	list = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		if (check_flags_struct(img))
			if (!(list = split_lines(line, list)))
				img->map = NULL;
		if (!(check_flags_struct(img)))
			check_str(line, img);
		if (img->flag.error)
			break;
	}
	if (!(list = split_lines(line, list)))
		img->map = NULL;
	close(fd);
	if (!(img->map = ft_split(list, '\n')))
	{
		free_double_arr(img->map);
		img->map = NULL;
	}
	img->flood_map = ft_split(list, '\n');
	free(list);

	//draw_map2d(map, img);

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
	clear_flags(img);
}

void 	func(t_data *img)
{
	int			count;
	t_sprites 	*save_head;
	count = 0;

	img->img = mlx_new_image(img->mlx, img->width , img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length , &img->endian);

	img->player.ang_start = img->player.angle - M_PI_6; // угол начала
	img->player.ang_end = img->player.angle + M_PI_6; // угол конца
	//draw_map_player(img);
	while (count < img->width)
	{
		img->player.ang_start > 2*M_PI ? img->player.ang_start -= 2*M_PI : 0;
		img->player.ang_start < 0 ? img->player.ang_start += 2*M_PI : 0;
		img->pixel = count; // координата столба по X
		tracer(img);
		img->player.ang_start += img->calc.ang_step;
		count++;
	}
	sort_len_list(img);
	save_head = img->sprites;
	while (save_head != NULL)
	{
		draw_sprite(img, save_head);
		save_head = save_head->next;
	}
	//all_len_sprites(img);
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
	else if (keycode == 2) // right
	{
		//if (img->map[(unsigned int)(img->player.y/img->cube_size)][(unsigned int)(img->player.x - 5 * sin(img->player.angle)/img->cube_size)] != '1')
			img->player.x -= 5 * sin(img->player.angle);
		//if (img->map[(unsigned int)(img->player.y + 5 * cos(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
			img->player.y += 5 * cos(img->player.angle);
	}
	else if (keycode == 0) // left
	{
		//if (img->map[(unsigned int)(img->player.y/img->cube_size)][(unsigned int)(img->player.x + 5 * sin(img->player.angle)/img->cube_size)] != '1')
			img->player.x += 5 * sin(img->player.angle);
		//if (img->map[(unsigned int)(img->player.y - 5 * cos(img->player.angle))/img->cube_size][(unsigned int)(img->player.x/img->cube_size)] != '1')
			img->player.y -= 5 * cos(img->player.angle);
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
	void_flags_struct(&img);

	img.color_sky = 0x5C5CFF;
	img.color_floor = 0xDFEEFE;

	parse(&img);

	img.cube_size = 32;
	img.calc.dis_to_proj = (img.width / 2.0) / tan(M_PI_6); // distance to proection
	img.calc.ang_step = M_PI_3 / img.width;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "Cub3d - drina");

	// textures 1
	img.txt1.txt = mlx_xpm_file_to_image(img.mlx, img.path.north, &img.txt1.width, &img.txt1.height);
	img.txt1.addr = (int*)mlx_get_data_addr(img.txt1.txt, &img.txt1.bits_per_pixel, &img.txt1.line_length , &img.txt1.endian);

	// textures 2
	img.txt2.txt = mlx_xpm_file_to_image(img.mlx, img.path.south, &img.txt2.width, &img.txt2.height);
	img.txt2.addr = (int*)mlx_get_data_addr(img.txt2.txt, &img.txt2.bits_per_pixel, &img.txt2.line_length , &img.txt2.endian);

	// textures 3
	img.txt3.txt = mlx_xpm_file_to_image(img.mlx, img.path.west, &img.txt3.width, &img.txt3.height);
	img.txt3.addr = (int*)mlx_get_data_addr(img.txt3.txt, &img.txt3.bits_per_pixel, &img.txt3.line_length , &img.txt3.endian);

	// textures 4
	img.txt4.txt = mlx_xpm_file_to_image(img.mlx, img.path.east, &img.txt4.width, &img.txt4.height);
	img.txt4.addr = (int*)mlx_get_data_addr(img.txt4.txt, &img.txt1.bits_per_pixel, &img.txt4.line_length , &img.txt4.endian);

	// sprite
	img.sprite.txt = mlx_xpm_file_to_image(img.mlx, img.path.sprite, &img.sprite.width, &img.sprite.height);
	img.sprite.addr = (int*)mlx_get_data_addr(img.sprite.txt, &img.sprite.bits_per_pixel, &img.sprite.line_length , &img.sprite.endian);

	img.calc.arr_min_len_wall = (double*)malloc(img.width * sizeof(double));

	if (img.map == NULL)
		return (0);

	check_player_sight(&img);
	img.sprites = NULL;
	flood_fill(&img, img.vert, img.horz, img.flood_map, '7');
	errors(&img);
	free_double_arr(img.flood_map);
	find_sprites(&img);
	func(&img);
	//draw_map_player(&img);

	mlx_hook(img.mlx_win, 2, 1L, &key, &img);
	mlx_loop(img.mlx);
	return (0);
}


