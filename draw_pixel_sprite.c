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

void		draw_pixel_sprite(t_data *img, int i, int j, double coef)
{
	int	color;

	color = img->sprite.addr[(int)(j * coef) * img->sprite.width +
						  	(int)(i * coef) % img->sprite.height];
	if (color > 0)
		my_mlx_pixel_put(img, img->calc.sprite_x + i, img->calc.sprite_y + j, color);
}
