/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:27:54 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:27:56 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		sprite_cond(int color, t_data *img, int y, int x)
{
	if (color > 0 && img->calc.sprite_y + x > 0 && img->calc.sprite_x + y > 0
		&& img->calc.sprite_x + y < img->width &&
		img->calc.sprite_y + x < img->height)
		return (1);
	else
		return (0);
}

void			draw_pixel_sprite(t_data *img, t_sprites *tmp,
							double coef, int sprite_h)
{
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < sprite_h)
	{
		x = 0;
		while (x < sprite_h)
		{
			if (img->calc.sprite_x + y < img->width && y + img->calc.sprite_x
			>= 0 && img->calc.arr_min_len_wall[(int)(img->calc.sprite_x
							+ y)] > tmp->len)
			{
				color = img->sprite.addr[(int)(x * coef) * img->sprite.width +
						(int)(y * coef) % img->sprite.height];
				if (sprite_cond(color, img, y, x))
					my_mlx_pixel_put(img, img->calc.sprite_x + y,
						img->calc.sprite_y + x, color);
			}
			x++;
		}
		y++;
	}
}
