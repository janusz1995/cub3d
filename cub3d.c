

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
		else if (sym == 'N')
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

double 		min_length(double x, double y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

double		find_horizontal(t_data *img)
{
	double	horz_y;
	double	horz_x;
	double	dis;
	double	dis_x;

	img->y = (int)(img->player.y / img->cube_size) * img->cube_size - 1;
	dis = img->player.y - img->y;
	dis_x = dis / tan(img->player.ang_start); // * tan(img->player.ang_start); // ang ?????????????????? 
	img->x = img->player.x - dis_x;
	while (img->map[(unsigned int)(img->y/img->cube_size)][(unsigned int)(img->x/img->cube_size)] != '1')
	{
		img->y -= img->cube_size;
		img->x -= img->cube_size / tan(img->player.ang_start);
	}
	horz_y = img->player.y - img->y;
	horz_x = img->player.x - img->x;
	dis = pow(horz_x, 2) + pow(horz_y, 2);
	return (sqrt(dis));
}

double 		find_vertical(t_data *img)
{
	double	horz_y;
	double	horz_x;
	double	dis;

	img->x = (int)(img->player.x / img->cube_size) * img->cube_size - 1;
	dis = img->player.x - img->x;
	img->y = dis / tan(img->player.ang_start); // ang ????????????
	while (img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] != '1')
	{
		img->x += img->cube_size;
		img->y += img->cube_size / tan(img->player.ang_start);
	}
	horz_y = img->player.y - img->y;
	horz_x = img->player.x - img->x;
	dis = pow(horz_x, 2) + pow(horz_y, 2);
	return (sqrt(dis));
}

void 	tracer(t_data *img)
{
	double horz_dot;
	double vert_dot;

	horz_dot = find_horizontal(img);
	vert_dot = find_vertical(img);
	img->calc.min_len = min_length(horz_dot, vert_dot);
	// fish eye fix
	draw_wall(img);
}

void 	draw_wall(t_data *img)
{
	double obj_h;
	int obj_start;
	int obj_end;

	obj_h = (img->calc.dis_to_proj / (img->calc.min_len * img->cube_size)) * img->height;
	obj_start = (img->height / 2) - (obj_h / 2);
	obj_end = (img->height / 2) + (obj_h / 2);

	while (obj_start < obj_end)
	{
		my_mlx_pixel_put(img, img->pixel, obj_start, 0x00FF0000);
		obj_start++;
	}
}


void 	func(t_data *img)
{
	int count;
	double ang_step;
	count = 0;

	img->img = mlx_new_image(img->mlx, 1920 , 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length , &img->endian);

	img->calc.dis_to_proj = (img->width / 2) / tan(M_PI_2 / 3);
	check_player_sight(img);
	ang_step = M_PI_6 / img->width;
	img->player.ang_start = img->player.angle - M_PI_6;
	img->player.ang_end = img->player.angle + M_PI_6;

	while (count < img->width)
	{
		//img->player.ang_start = img->player.angle - M_PI_6;
		//img->player.ang_end = img->player.angle + M_PI_6;

		// need change angle and plus angle step:
		// angle step: (pi / 3) / width;                               !!!!!!!!!!!
		img->pixel = count;
		tracer(img);
		img->player.ang_start += ang_step;
		count++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	//mlx_destroy_image(img->mlx, img->img);
}

/// Draw 32 pixels
/*




void 	draw_cub32(int x, int y, int c, t_data *img)
{
	int x_max, y_max, color;
	x_max = x + 32;
	y_max = y + 32;
	img->x = x;
	//write(1, "fail\n", 5);
	if (c == '0')
		color = 0x00FF0000; // color - red
	else if (c == '1')
		color = 0x000000FF; // color - blue
	while (y < y_max)
	{
		x = img->x;
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

*/
/*	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);*//*

}

void 	draw_map_player(t_data *img)
{

	img->img = mlx_new_image(img->mlx, 1920 , 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length , &img->endian);

	draw_map2d(img);
	draw_player(img->player.x + 10, img->player.y + 10, img);

	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);

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
			else if (img->map[i][j] == 'N')

			j++;
			count_x += 32;
		}
		count_y += 32;
		i++;
	}
}

int 	key(int keycode, t_data *img) {

	if (keycode == 126) // up
	{
		img->player.y -= img->speed;
	}
	else if (keycode == 125) // down
	{
		img->player.y += img->speed;
	}
	else if (keycode == 124) // right
	{
		img->player.x += img->speed;
	}
	else if (keycode == 123) // left
	{
		img->player.x -= img->speed;
	}
	mlx_destroy_image(img->mlx, img->img);
	draw_map_player(img);
	return (1);
}
*/

int		main()
{

	t_data img;
	img.width = 1920;
	img.height = 1080;
	img.cube_size = 32;
	//img.player.x = 700;
	//img.player.y = 800;

	//img.color = 0x0000FF00;
	//img.speed = 5;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "Cub3d - drina");

	img.map = parse_map();
	func(&img);
	//draw_map_player(&img);

	//mlx_hook(img.mlx_win, 2, 0L, &key, &img);
	mlx_loop(img.mlx);
	return (0);
}


