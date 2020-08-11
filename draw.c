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

void 	clear_flags(t_data *img)
{
	img->flag.north = 0;
	img->flag.south = 0;
	img->flag.east = 0;
	img->flag.west = 0;
}

int 	color_in_textures(t_data *img, double coef, int obj_start, int save)
{
	int color;
	if (img->flag.north == 1)
		color = img->txt1.addr[(int)((obj_start - save) * coef) * img->txt1.width
				+ ((int)(img->calc.x_or_y * 2) % img->txt1.width)];
	else if (img->flag.south == 1)
		color = img->txt2.addr[(int)((obj_start - save) * coef) * img->txt2.width
				+ (img->txt1.width - ((int)(img->calc.x_or_y * 2) % img->txt1.width))];
	else if (img->flag.east == 1)
		color = img->txt3.addr[(int)((obj_start - save) * coef) * img->txt3.width
				+ ((int)(img->calc.x_or_y * 2) % img->txt3.width)];
	else
		color = img->txt4.addr[(int)((obj_start - save) * coef) * img->txt4.width
				+ ((img->txt4.width - 1) - ((int)(img->calc.x_or_y * 2) % img->txt4.width))];
	return (color);
}

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
	int		obj_h;
	int		obj_start;
	int		obj_end;
	int		save;
	double	coef;

	obj_h = (int)((img->calc.dis_to_proj /
					(img->calc.min_len * img->cube_size)) * img->height);
	obj_start = (img->height / 2) - (obj_h / 2);
	obj_end = (img->height / 2) + (obj_h / 2);
	coef = 64.0 / obj_h;
	save = obj_start;
	if (obj_end > img->height)
		obj_end = img->height - 1;
	if (obj_start < 0)
		obj_start = 0;
	draw_sky(img, obj_start);
	while (obj_start < obj_end)
	{
		my_mlx_pixel_put(img, img->pixel, obj_start,
							color_in_textures(img, coef, obj_start, save));
		obj_start++;
	}
	draw_floor(img, obj_start);
}
