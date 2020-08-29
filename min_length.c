/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:30:36 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:30:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		min_length(double horz, double vert, t_data *img)
{
	if (horz > vert)
	{
		img->calc.x_or_y = img->vert_y;
		if (img->player.ang_start < M_PI + M_PI_2 &&
				img->player.ang_start > M_PI_2)
			img->flag.west = 1;
		else
			img->flag.east = 1;
		return (vert);
	}
	else
	{
		img->calc.x_or_y = img->horz_x;
		if (img->player.ang_start < 2 * M_PI && img->player.ang_start > M_PI)
			img->flag.north = 1;
		else
			img->flag.south = 1;
		return (horz);
	}
}
