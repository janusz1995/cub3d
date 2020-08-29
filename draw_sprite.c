/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:28:03 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:28:05 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_data *img, t_sprites *tmp)
{
	int		sprite_h;
	double	coef;

	tmp->len = sqrt(pow(tmp->x - img->player.x, 2) +
			pow(tmp->y - img->player.y, 2));
	sprite_h = (int)((img->calc.dis_to_proj / (tmp->len * img->cube_size) *
			img->height));
	img->calc.sprite_dir = atan2((tmp->y - img->player.y), (tmp->x -
								img->player.x));
	coef = 64.0 / sprite_h;
	while (img->calc.sprite_dir - img->player.angle > M_PI)
		img->calc.sprite_dir -= 2 * M_PI;
	while (img->calc.sprite_dir - img->player.angle < -M_PI)
		img->calc.sprite_dir += 2 * M_PI;
	img->calc.sprite_dir = img->calc.sprite_dir - img->player.angle;
	img->calc.sprite_x = img->calc.sprite_dir * (img->width / 2) /
						(M_PI / 6) + img->width / 2 - sprite_h / 2;
	img->calc.sprite_y = img->height / 2 - sprite_h / 2;
	draw_pixel_sprite(img, tmp, coef, sprite_h);
}
