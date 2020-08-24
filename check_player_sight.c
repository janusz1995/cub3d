/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_sight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:26:35 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:26:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_sight(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (check_direction_player(img->map[i][j], img))
			{
				img->vert = j;
				img->horz = i;
				img->player.letter = img->map[i][j];
				img->player.x = (j * img->cube_size) + (img->cube_size/2);
				img->player.y = (i * img->cube_size) + (img->cube_size/2);
				break ;
			}
			j++;
		}
		i++;
	}
}
