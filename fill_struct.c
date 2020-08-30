/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:28:34 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:28:36 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_flags_struct(t_data *img)
{
	return (img->flag.sky && img->flag.floor && img->flag.height
				&& img->flag.width && img->flag.north && img->flag.south
				&& img->flag.west && img->flag.east && img->flag.sprite);
}

void	fill_width_and_height(t_data *img, char *str)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (check_num_lines(tmp, 3) == 1 && (check_line(tmp[1]) &&
			check_line(tmp[2])) && !img->flag.height && !img->flag.width)
	{
		img->width = ft_atoi(tmp[1]);
		img->height = ft_atoi(tmp[2]);
		img->flag.width = 1;
		img->flag.height = 1;
		check_max_and_min_screensize(img);
	}
	else
		img->flag.error = 1;
	free_double_arr(tmp);
}

void	fill_side(t_data *img, char *str, char **side, int *flag)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if (check_num_lines(tmp, 2) == 1 && !(*flag))
	{
		(*side) = ft_strdup(tmp[1]);
		(*flag) = 1;
	}
	else
		img->flag.error = 1;
	free_double_arr(tmp);
}

void	fill_color(char *str, int *color, t_data *img, int *flag)
{
	char	**tmp;

	while (*str == ' ')
		str++;
	tmp = ft_split(str, ',');
	if (check_num_lines(tmp, 3) != 1 ||
		ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[0]) > 255 ||
		ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[1]) > 255 ||
		ft_atoi(tmp[2]) < 0 || ft_atoi(tmp[2]) > 255)
		img->error.no_valid_color = 1;
	else if (check_num_lines(tmp, 3) == 1 && check_line(tmp[0]) &&
			check_line(tmp[1]) && check_line(tmp[2]) && !(*flag))
	{
		(*color) = 0 << 24 | ft_atoi(tmp[0]) << 16 | ft_atoi(tmp[1]) << 8 |
								ft_atoi(tmp[2]) << 0;
		(*flag) = 1;
	}
	else
		img->flag.error = 1;
	free_double_arr(tmp);
}
