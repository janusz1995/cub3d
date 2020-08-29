/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:31:02 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:31:04 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprites		*lstnew(int y, int x, int cube_size)
{
	t_sprites	*list;

	list = (t_sprites*)malloc(sizeof(t_sprites));
	if (!list)
		return (NULL);
	list->x = x + cube_size / 2;
	list->y = y + cube_size / 2;
	list->len = 0;
	list->next = NULL;
	return (list);
}
