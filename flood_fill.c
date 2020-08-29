/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:29:45 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:29:47 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_data *img, int x, int y, char new_sym)
{
	if (x < 0 || y < 0 || x > img->calc.x_max || y >= img->calc.y_max ||
		img->flood_map[y][x] == ' ' || img->flood_map[y][x] == '\0')
	{
		img->error.no_valid_map = 1;
		errors(img);
	}
	if (img->flood_map[y][x] != new_sym && img->flood_map[y][x] != ' ' &&
			img->flood_map[y][x] != '\0' && img->flood_map[y][x] != '1')
	{
		img->flood_map[y][x] = new_sym;
		flood_fill(img, x, y - 1, new_sym);
		flood_fill(img, x, y + 1, new_sym);
		flood_fill(img, x + 1, y, new_sym);
		flood_fill(img, x - 1, y, new_sym);
	}
}
