/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:29:23 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:29:26 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_sprites(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == '2')
				add_back_sprite(img, (lstnew((i * img->cube_size),
							(j * img->cube_size), img->cube_size)));
			j++;
		}
		i++;
	}
}
