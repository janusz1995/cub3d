/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_and_min_screensize.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 23:50:08 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 23:50:10 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	check_max_and_min_screensize(t_data *img)
{
	int h;
	int w;

	mlx_get_screen_size(img->mlx, &w, &h);
	if (img->height > h)
		img->height = h;
	if (img->width > w)
		img->width = w;
	if (img->height < 200)
		img->height = 200;
	if (img->width < 320)
		img->width = 320;
}
