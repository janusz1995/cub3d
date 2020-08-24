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

void 	x_and_y_max(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (j > img->calc.x_max)
				img->calc.x_max = j;
			j++;
		}
		i++;
	}
	img->calc.x_max++;
	img->calc.y_max = i;
}
