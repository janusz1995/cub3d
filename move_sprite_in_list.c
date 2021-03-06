/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite_in_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:32:11 by drina             #+#    #+#             */
/*   Updated: 2020/08/25 15:32:13 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_sprite(t_data *img)
{
	t_sprites	*save_head;

	save_head = img->sprites;
	while (save_head != NULL)
	{
		draw_sprite(img, save_head);
		save_head = save_head->next;
	}
}
