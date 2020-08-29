/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_and_y_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 00:15:37 by drina             #+#    #+#             */
/*   Updated: 2020/08/25 00:15:40 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		valid_str(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\n' || *str == '\0')
		return (0);
	else
		return (1);
}

static	int		valid_param(t_data *img, int i, int j)
{
	return (img->map[i][j] == 'N' || img->map[i][j] == 'S' ||
			img->map[i][j] == 'W' || img->map[i][j] == 'E' ||
			img->map[i][j] == '1' || img->map[i][j] == '2' ||
			img->map[i][j] == '0' || img->map[i][j] == ' ');
}

void			x_and_y_max(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (!valid_param(img, i, j) || !valid_str(img->map[i]))
				img->error.no_valid_map = 1;
			if (img->map[i][j] == 'N' || img->map[i][j] == 'S' ||
					img->map[i][j] == 'W' || img->map[i][j] == 'E')
				img->error.num_players++;
			if (j > img->calc.x_max)
				img->calc.x_max = j;
			j++;
		}
		i++;
	}
	img->calc.x_max++;
	img->calc.y_max = i;
}
