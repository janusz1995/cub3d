/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:44:28 by drina             #+#    #+#             */
/*   Updated: 2020/08/07 22:44:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	draw_floor(t_data *img, int obj_start)
{
	int floor;

	floor = obj_start;
	while (floor < img->height - 1)
		my_mlx_pixel_put(img, img->pixel, floor++, 0xDFEEFE);
}

void 	draw_sky(t_data *img, int obj_start)
{
	int sky;

	sky = 0;
	while (sky < obj_start)
		my_mlx_pixel_put(img, img->pixel, sky++, 0x5C5CFF);
}

void 	draw_wall(t_data *img)
{
	int obj_h;
	int obj_start;
	int obj_end;

	obj_h = (int)((img->calc.dis_to_proj / (img->calc.min_len * img->cube_size)) * img->height);
	obj_start = (img->height / 2) - (obj_h / 2);
	obj_end = (img->height / 2) + (obj_h / 2);
	if (obj_end > img->height)
		obj_end = img->height - 1;
	if (obj_start < 0)
		obj_start = 0;
	draw_sky(img, obj_start);
	while (obj_start < obj_end)
		my_mlx_pixel_put(img, img->pixel, obj_start++, 0x3F5F7F);
	draw_floor(img, obj_start);
}