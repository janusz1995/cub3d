/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:29:34 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:29:37 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_cond_one(t_data *img)
{
	if (img->vert_y > 0 && img->vert_x > 0 && img->vert_x <
				img->calc.x_max * img->cube_size &&
			img->vert_y < img->calc.y_max * img->cube_size &&
			img->map[(unsigned int)img->vert_y / img->cube_size]
					[(unsigned int)img->vert_x / img->cube_size] == '1')
		return (1);
	else
		return (0);
}

static int		check_cond_no_one(t_data *img)
{
	if (img->vert_y > 0 && img->vert_x > 0 && img->vert_x <
			img->calc.x_max * img->cube_size &&
		img->vert_y < img->calc.y_max * img->cube_size &&
		img->map[(unsigned int)img->vert_y / img->cube_size]
				[(unsigned int)img->vert_x / img->cube_size] != '1')
		return (1);
	else
		return (0);
}

static	void	vert_y(t_data *img)
{
	if (img->player.ang_start < (M_PI * 2) && img->player.ang_start > M_PI)
	{
		if (img->player.ang_start > M_PI && img->player.ang_start <
					(M_PI + M_PI_2))
			img->vert_y = img->player.y - img->calc.dis_x *
							tan(img->player.ang_start - M_PI);
		else
			img->vert_y = img->player.y - img->calc.dis_x *
							tan(2 * M_PI - img->player.ang_start);
	}
	else if (img->player.ang_start == (M_PI * 2) ||
			img->player.ang_start == M_PI || img->player.ang_start == 0)
		img->vert_y = img->player.y;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->vert_y = img->player.y + img->calc.dis_x *
								tan(img->player.ang_start);
		else
			img->vert_y = img->player.y + img->calc.dis_x *
								tan(M_PI - img->player.ang_start);
	}
}

void			vert_x_and_y(t_data *img)
{
	if (img->player.ang_start < (M_PI + M_PI_2) &&
				img->player.ang_start > M_PI_2)
		img->vert_x = (int)(img->player.x / img->cube_size) *
						img->cube_size - 0.00000000001;
	else
		img->vert_x = (int)(img->player.x / img->cube_size) *
						img->cube_size + img->cube_size;
	if (img->player.ang_start < (M_PI + M_PI_2) &&
				img->player.ang_start > M_PI_2)
		img->calc.dis_x = img->player.x - img->vert_x;
	else
		img->calc.dis_x = img->vert_x - img->player.x;
	vert_y(img);
}

double			find_vertical(t_data *img)
{
	double vert_dis_y;
	double vert_dis_x;

	if (img->player.ang_start == (M_PI + M_PI_2) ||
			img->player.ang_start == M_PI_2)
		return (INFINITY);
	else
		vert_x_and_y(img);
	while (check_cond_no_one(img))
		quarters_vert(img);
	if (check_cond_one(img))
	{
		vert_dis_y = img->player.y - img->vert_y;
		vert_dis_x = img->player.x - img->vert_x;
		img->calc.dis = pow(vert_dis_x, 2) + pow(vert_dis_y, 2);
		return (sqrt(img->calc.dis));
	}
	else
		return (INFINITY);
}
