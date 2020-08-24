/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:26:46 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:26:47 by drina            ###   ########.fr       */
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

void 	void_flags_struct(t_data *img)
{
	img->flag.sprite = 0;
	img->flag.north = 0;
	img->flag.south = 0;
	img->flag.west = 0;
	img->flag.east = 0;
	img->flag.floor = 0;
	img->flag.sky = 0;
	img->flag.error = 0;
	img->error.no_valid_map = 0;
	img->error.num_players = 0;
	img->error.textures = 0;
	img->flag.screenshot = 0;
}
