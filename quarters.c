/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:02:35 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:31:16 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		quarters_horz(t_data *img)
{
	if (img->player.ang_start > 0 && img->player.ang_start < M_PI)
		img->horz_y += img->cube_size;
	else
		img->horz_y -= img->cube_size;
	if (img->player.ang_start > M_PI_2 &&
			img->player.ang_start < (M_PI_2 + M_PI))
	{
		if (img->player.ang_start < (M_PI + M_PI_2) &&
				img->player.ang_start > M_PI)
			img->horz_x -= img->cube_size * tan((M_PI + M_PI_2) -
					img->player.ang_start);
		else
			img->horz_x -= img->cube_size * tan(img->player.ang_start - M_PI_2);
	}
	else if (img->player.ang_start == (M_PI_2 + M_PI) ||
				img->player.ang_start == M_PI_2)
		img->horz_x = img->horz_x;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->horz_x += img->cube_size * tan(M_PI_2 - img->player.ang_start);
		else
			img->horz_x += img->cube_size *
					tan(img->player.ang_start - (M_PI + M_PI_2));
	}
}

void		quarters_vert(t_data *img)
{
	if (img->player.ang_start < (M_PI + M_PI_2) &&
			img->player.ang_start > M_PI_2)
		img->vert_x -= img->cube_size;
	else
		img->vert_x += img->cube_size;
	if (img->player.ang_start > M_PI && img->player.ang_start < (2 * M_PI))
	{
		if (img->player.ang_start > M_PI &&
				img->player.ang_start < (M_PI + M_PI_2))
			img->vert_y -= img->cube_size * tan(img->player.ang_start - M_PI);
		else
			img->vert_y -= img->cube_size *
					tan(2 * M_PI - img->player.ang_start);
	}
	else if (img->player.ang_start == (M_PI * 2) || img->player.ang_start
					== M_PI || img->player.ang_start == 0)
		img->vert_y = img->vert_y;
	else
	{
		if (img->player.ang_start < M_PI_2 && img->player.ang_start > 0)
			img->vert_y += img->cube_size * tan(img->player.ang_start);
		else
			img->vert_y += img->cube_size * tan(M_PI - img->player.ang_start);
	}
}
