

#include <stdio.h>
#include "mlx.h"
#include "cub3d.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/// Split 2 line and \n

char *split_lines(char *line, char *list)
{
	char *tmp;

	tmp = list;
	list = ft_strjoin(list, line);
	free(tmp);
	tmp = list;
	list = ft_strjoin(list, "\n");
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
		printf("%d", fd);
	list = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		list = split_lines(line, list);
	}
	list = split_lines(line, list);
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

/* void    quarters_vert(t_data *img)
{
    if (img->player.ang_start <= (M_PI + M_PI_2) && img->player.ang_start >= M_PI_2)
        img->x -= img->cube_size;
    else
       img->x += img->cube_size;

    if (img->player.ang_start < M_PI_2 && img->player.ang_start > (M_PI_2 + M_PI))
        img->y += img->cube_size / tan(img->player.ang_start);
    else if (img->player.ang_start == M_PI || img->player.ang_start == 0)
        img->y = img->y;
    else
        img->y -= img->cube_size / tan(img->player.ang_start);
}

void    quarters_horz(t_data *img)
{
    if (img->player.ang_start >= 0 && img->player.ang_start <= M_PI)
        img->y += img->cube_size;
    else
        img->y -= img->cube_size;

    if (img->player.ang_start < M_PI_2 && img->player.ang_start > (M_PI_2 + M_PI))
        img->x += img->cube_size / tan(img->player.ang_start);
    else if (img->player.ang_start == (M_PI_2 + M_PI) || img->player.ang_start == M_PI_2)
        img->x = img->x;
    else
        img->x -= img->cube_size / tan(img->player.ang_start);
}
 */

//void 	draw_sky(t_data *img)
//{
//	int x, y;
//
//	y = img->height / 2;
//	while (y > 0)
//	{
//		x = 0;
//		while (x < img->width - 1)
//		{
//			my_mlx_pixel_put(img, x, y, 0x5C5CFF);
//			x++;
//		}
//		y--;
//	}
//}

//void 	draw_floor(t_data *img)
//{
//	int x, y;
//
//	y = img->height / 2;
//	while (y < img->height - 1)
//	{
//		x = 0;
//		while (x < img->width - 1)
//		{
//			my_mlx_pixel_put(img, x, y, 0xDFEEFE);
//			x++;
//		}
//		y++;
//	}
//}


double 		min_length(double x, double y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

double		find_horizontal(t_data *img)
{
	double	horz_dis_y;
	double	horz_dis_x;

	if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI * 2))
		img->y = (int)(img->player.y / img->cube_size) * img->cube_size - 0.00000000001; //координата точки пересечения с 1 квадратом Y
	else if (img->player.ang_start == M_PI || img->player.ang_start == (M_PI * 2) || img->player.ang_start == 0)
		return (INFINITY);
	else
		img->y = (int)(img->player.y / img->cube_size) * img->cube_size + img->cube_size;

	if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI * 2))
		img->calc.dis_y = img->player.y - img->y;
	else
		img->calc.dis_y = img->y - img->player.y;
	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
	{
		if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI)
			img->x = img->player.x - img->calc.dis_y * tan((M_PI + M_PI_2) - img->player.ang_start);
		else
			img->x = img->player.x - img->calc.dis_y * tan(img->player.ang_start - M_PI_2);
	}
	else if (img->player.ang_start == (M_PI_2 + M_PI) || img->player.ang_start == M_PI_2)
		img->x = img->player.x;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->x = img->calc.dis_y * tan(M_PI_2 - img->player.ang_start) + img->player.x;
		else
			img->x = img->calc.dis_y * tan(img->player.ang_start - (M_PI + M_PI_2)) + img->player.x;
	}
	img->calc.dis = 0;
	while (img->y > 0 && img->x > 0 && img->y < 14*32 && img->x < 35*32 && img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] != '1')
	{
		quarters_horz(img);
	}
	if (img->y > 0 && img->x > 0 && img->y < 14*32 && img->x < 35*32 && img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] == '1')
	{
		horz_dis_y = img->player.y - img->y;
		horz_dis_x = img->player.x - img->x;
		img->calc.dis = pow(horz_dis_x, 2) + pow(horz_dis_y, 2);
		return (sqrt(img->calc.dis));
	}
	else
		return (INFINITY);
}

double 		find_vertical(t_data *img)
{
	double	vert_y = 0;
	double	vert_x = 0;

	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
		img->x = (int)(img->player.x / img->cube_size) * img->cube_size - 0.00000000001;
	else if (img->player.ang_start == (M_PI + M_PI_2) || img->player.ang_start == M_PI_2)
		return (INFINITY);
	else
		img->x = (int)(img->player.x / img->cube_size) * img->cube_size + img->cube_size;

	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
		img->calc.dis_x = img->player.x - img->x;
	else
		img->calc.dis_x = img->x - img->player.x;

	if (img->player.ang_start < (M_PI * 2) && img->player.ang_start > M_PI)
	{
		if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI + M_PI_2))
			img->y = img->player.y - img->calc.dis_x * tan(img->player.ang_start - M_PI);
		else
			img->y = img->player.y - img->calc.dis_x * tan(2 * M_PI - img->player.ang_start);
	}
	else if (img->player.ang_start == (M_PI * 2) || img->player.ang_start == M_PI || img->player.ang_start == 0)
		img->y = img->player.y;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->y = img->player.y + img->calc.dis_x * tan(img->player.ang_start);
		else
			img->y = img->player.y + img->calc.dis_x * tan(M_PI - img->player.ang_start);
	}
	img->calc.dis = 0;
	while (img->y > 0 && img->x > 0 && img->x < 35 * 32 && img->y < 14*32 && img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] != '1')
	{
		quarters_vert(img);
	}
	if (img->y > 0 && img->x > 0 && img->x < 35 * 32 && img->y < 14*32 && img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] == '1')
	{
		vert_y = img->player.y - img->y;
		vert_x = img->player.x - img->x;
		img->calc.dis = pow(vert_x, 2) + pow(vert_y, 2);
		return (sqrt(img->calc.dis));
	}
	else
		return (INFINITY);
}

void 	tracer(t_data *img)
{
	double horz_len;
	double vert_len;
	//int i = 0;

	horz_len = find_horizontal(img);
	vert_len = find_vertical(img);
	img->calc.min_len = min_length(horz_len, vert_len);
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
}

//void 	draw_wall(t_data *img)
//{
//	int obj_h;
//	int obj_start;
//	int obj_end;
//
//	obj_h = (int)((img->calc.dis_to_proj / (img->calc.min_len * img->cube_size)) * img->height);
//	obj_start = (img->height / 2) - (obj_h / 2);
//	obj_end = (img->height / 2) + (obj_h / 2);
//	if (obj_end > img->height)
//		obj_end = img->height - 1;
//	if (obj_start < 0)
//		obj_start = 0;
//	while (obj_start < obj_end)
//	{
//		my_mlx_pixel_put(img, img->pixel, obj_start, 0x3F5F7F);
//		obj_start++;
//	}
//}


void 	func(t_data *img)
{
	int count;
	double ang_step;
	count = 0;

	img->img = mlx_new_image(img->mlx, 1920 , 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length , &img->endian);

	img->calc.dis_to_proj = (img->width / 2) / tan(M_PI_6); // Расстояние до проекции
	ang_step = M_PI_3 / img->width;
	img->player.ang_start = img->player.angle - M_PI_6; // угол начала
	img->player.ang_end = img->player.angle + M_PI_6; // угол конца
	//draw_map_player(img);
//	draw_sky(img);
//	draw_floor(img);
	while (count < img->width)
	{
		img->player.ang_start > 2*M_PI ? img->player.ang_start -= 2*M_PI : 0;
		img->player.ang_start < 0 ? img->player.ang_start += 2*M_PI : 0;
		img->pixel = count; // координата столба по X
		tracer(img);
		img->player.ang_start += ang_step;
		count++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

/// Draw 32 pixels

void 	draw_cub32(int x, int y, int c, t_data *img)
{
	int x_max, y_max, color , x_img;
	x_max = x + 32;
	y_max = y + 32;
	x_img = x;
	//write(1, "fail\n", 5);
	if (c == '0')
		color = 0x00FF0000; // color - red
	else if (c == '1')
		color = 0x000000FF; // color - blue
	while (y < y_max)
	{
		x = x_img;
		while (x < x_max)
			my_mlx_pixel_put(img, x++, y, color);
		y++;
	}
}

void 	draw_player(int x_max, int y_max, t_data *img)
{
	int count_y, count_x;

	count_x = img->player.x;

	while (count_x++ < x_max)
	{
		count_y = img->player.y;
		while (count_y++ < y_max)
			my_mlx_pixel_put(img, count_x, count_y, img->color);
	}
}


void 	draw_map_player(t_data *img)
{
	draw_map2d(img);
	draw_player(img->player.x + 1, img->player.y + 1, img);
}

/// Draw map top view

void	draw_map2d(t_data *img)
{
	int count_y, count_x, i, j;

	count_y = 0;
	i = 0;

	while (img->map[i])
	{
		j = 0;
		count_x = 0;
		while (img->map[i][j])
		{
			if(img->map[i][j] == '1' || img->map[i][j] == '0')
				draw_cub32(count_x, count_y, img->map[i][j], img);
			j++;
			count_x += 32;
		}
		count_y += 32;
		i++;
	}
}

int 	key(int keycode, t_data *img) 
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 126) // up
	{
		img->player.y += 5 * sin(img->player.angle);
		img->player.x += 5 * cos(img->player.angle);
	}
	else if (keycode == 125) // down
	{
		img->player.y -= 5 * sin(img->player.angle);
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
	img.calc.dis_to_proj = (img.width / 2) / tan(M_PI_6);
	//img.player.x = 700;
	//img.player.y = 800;

	//img.color = 0x0000FF00;
	//img.speed = 5;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "Cub3d - drina");

	img.map = parse_map();
	check_player_sight(&img);
	func(&img);
	//draw_map_player(&img);

	mlx_hook(img.mlx_win, 2, 1L, &key, &img);
	mlx_loop(img.mlx);
	return (0);
}


