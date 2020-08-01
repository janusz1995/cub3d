/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:02:35 by drina             #+#    #+#             */
/*   Updated: 2020/08/01 19:02:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    quarters_horz(t_data *img)
{
    if (img->player.ang_start <= M_PI_2 && img->player.ang_start >= M_2_PI)
    {
        // first quarter
        img->y += img->cube_size;
		img->x += img->cube_size / tan(img->player.ang_start);
    }
    else if (img->player.ang_start >= M_PI_2 && img->player.ang_start <= M_PI)
    {
        // second quarter
        img->y += img->cube_size;
		img->x -= img->cube_size / tan(img->player.ang_start);
    }
    else if (img->player.ang_start >= M_PI && img->player.ang_start <= (M_PI + M_PI_2))
    {
        // third quarter
        img->y -= img->cube_size;
		img->x -= img->cube_size / tan(img->player.ang_start);
    }
    else if (img->player.ang_start > (M_PI + M_PI_2) && img->player.ang_start < M_2_PI)
    {
        // fourth quarter
        img->y -= img->cube_size;
		img->x += img->cube_size / tan(img->player.ang_start);
    }
}

/* double    first_quarter(t_data *img)
{
    double	horz_y;
	double	horz_x;
	double	dis_x;
    double	dis_y;

	img->x = (int)(img->player.x / img->cube_size) * img->cube_size - 1;
	dis_x = img->player.x - img->x;



    dis_y = dis_x / tan(img->player.ang_start); // ang ???????????? 
    img->y = img->player.y - dis_y; //


	while (img->map[(unsigned int)img->y/img->cube_size][(unsigned int)img->x/img->cube_size] != '1')
	{
		img->x += img->cube_size;
		img->y += img->cube_size / tan(img->player.ang_start);
	}




	horz_y = img->player.y - img->y;
	horz_x = img->player.x - img->x;
	dis_x = pow(horz_x, 2) + pow(horz_y, 2);
	return (sqrt(dis_x));
} */