/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:27:00 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:27:03 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

void		parse(t_data *img, char *filename)
{
	int		fd;
	char	*list;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error:\nFile Does Not Exist\n", 1);
		all_free(img);
		exit(0);
	}
	list = ft_strdup("");
	list = read_file(img, fd, list);
	close(fd);
	valid_map(list, img);
	if (!(img->map = ft_split(list, '\n')))
		img->map = NULL;
	if (!(img->flood_map = ft_split(list, '\n')))
		img->flood_map = NULL;
	free(list);
	list = NULL;
}

void		tracer(t_data *img)
{
	double horz_len;
	double vert_len;

	horz_len = find_horizontal(img);
	vert_len = find_vertical(img);
	img->calc.min_len = min_length(horz_len, vert_len, img);
	img->calc.arr_min_len_wall[img->pixel] = img->calc.min_len;
	img->calc.min_len = img->calc.min_len *
						cos(img->player.angle - img->player.ang_start);
	draw_wall(img);
	clear_flags(img);
}

void		func(t_data *img)
{
	int count;

	count = 0;
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
									&img->line_length, &img->endian);
	img->player.ang_start = img->player.angle - M_PI_6;
	img->player.ang_end = img->player.angle + M_PI_6;
	while (count < img->width)
	{
		img->player.ang_start > 2 * M_PI ?
				img->player.ang_start -= 2 * M_PI : 0;
		img->player.ang_start < 0 ? img->player.ang_start += 2 * M_PI : 0;
		img->pixel = count;
		tracer(img);
		img->player.ang_start += img->calc.ang_step;
		count++;
	}
	if (img->sprites != NULL)
	{
		sort_len_list(img);
		move_sprite(img);
	}
	screenshot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void		game(t_data *img)
{
	check_player_sight(img);
	x_and_y_max(img);
	flood_fill(img, img->vert, img->horz, '7');
	errors(img);
	free_double_arr(img->flood_map);
	find_sprites(img);
	func(img);
}

int			main(int argc, char **argv)
{
	t_data img;

	void_flags_struct(&img);
	if (argc != 2 && argc != 3)
	{
		ft_putstr_fd("Error:\nWrong number of arguments\n", 1);
		return (0);
	}
	check_argv(argc, argv, &img);
	parse(&img, argv[1]);
	const_param(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width,
								img.height, "Cub3d - drina");
	get_textures(&img);
	if (img.map == NULL)
		return (0);
	game(&img);
	mlx_hook(img.mlx_win, 2, 1L, &key, &img);
	mlx_hook(img.mlx_win, 17, 0L, &close_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
