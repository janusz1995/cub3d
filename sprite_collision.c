/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:29:43 by drina             #+#    #+#             */
/*   Updated: 2020/08/25 15:29:45 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sprite_collision(t_data *img)
{
	t_sprites	*head;
	t_sprites	*tmp;

	tmp = img->sprites;
	head = img->sprites;
	while (head->next != NULL)
		head = head->next;
	while (tmp->next != head)
		tmp = tmp->next;
	if (head->x == img->player.x && head->y == img->player.y)
	{
		free(head);
		tmp->next = NULL;
	}
}
