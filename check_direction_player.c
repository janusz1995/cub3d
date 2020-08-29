/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:25:50 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:25:51 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_direction_player(int sym, t_data *img)
{
	if (sym == 'N' || sym == 'S' || sym == 'W' || sym == 'E')
	{
		img->player.ang_fov = M_PI / 3;
		if (sym == 'E')
			img->player.angle = 0;
		else if (sym == 'S')
			img->player.angle = M_PI_2;
		else if (sym == 'W')
			img->player.angle = M_PI;
		else
			img->player.angle = M_PI_2 * 3;
		return (1);
	}
	else
		return (0);
}
