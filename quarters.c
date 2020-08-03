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
    if (img->player.ang_start >= 0 && img->player.ang_start <= M_PI)
        img->y += img->cube_size;
    else
        img->y -= img->cube_size;

    if (img->player.ang_start < M_PI_2 && img->player.ang_start > (M_PI_2 + M_PI))
    {
        img->x += img->cube_size / tan(img->player.ang_start);
    
    
    }
    else if (img->player.ang_start == (M_PI_2 + M_PI) || img->player.ang_start == M_PI_2)
        img->x = img->x;
    else
        img->x -= img->cube_size / tan(img->player.ang_start);
}

void    quarters_vert(t_data *img)
{
    if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
        img->x -= img->cube_size;
    else if (img->player.ang_start > (M_PI + M_PI_2) && img->player.ang_start < M_PI_2)
       img->x += img->cube_size;

    if (img->player.ang_start > M_PI && img->player.ang_start < (2 * M_PI))
    {
        if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI + M_PI_2))
            img->y -= img->cube_size / -tan(img->player.ang_start);
        else
            img->y -= img->cube_size / tan(img->player.ang_start);
    }
    else if (img->player.ang_start == M_PI || img->player.ang_start == 0)
        img->y = img->y;
    else
    {
        if (img->player.ang_start < M_PI_2 && img->player.ang_start > 0)
            img->y += img->cube_size / -tan(img->player.ang_start);
        else
            img->y += img->cube_size / tan(img->player.ang_start);
    }
}