/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 01:22:16 by drina             #+#    #+#             */
/*   Updated: 2020/08/25 01:22:18 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	up(t_data *img)
{
	if (img->map[(unsigned int)(img->player.y +
            20 * sin(img->player.angle)) / img->cube_size]
			[(unsigned int)img->player.x / img->cube_size] != '1')
		img->player.y += 5 * sin(img->player.angle);
	if (img->map[(unsigned int)img->player.y / img->cube_size]
		[(unsigned int)(img->player.x +
                    20 * cos(img->player.angle)) / img->cube_size] != '1')
		img->player.x += 5 * cos(img->player.angle);
}

static	void	down(t_data *img)
{
	if (img->map[(unsigned int)(img->player.y -
            20 * sin(img->player.angle)) / img->cube_size]
		[(unsigned int)img->player.x / img->cube_size] != '1')
		img->player.y -= 5 * sin(img->player.angle);
	if (img->map[(unsigned int)img->player.y / img->cube_size]
		[(unsigned int)(img->player.x -
                    20 * cos(img->player.angle)) / img->cube_size] != '1')
		img->player.x -= 5 * cos(img->player.angle);
}

static	void	right(t_data *img)
{
//	 if (img->map[(unsigned int)(img->player.y / img->cube_size)]
//	 	[(unsigned int)(img->player.x - 20 * sin(img->player.angle)
//	 	/ img->cube_size)] == '1' || img->map[(unsigned int)(img->player.y +
//             20 * cos(img->player.angle)) / img->cube_size]
//	 	[(unsigned int)img->player.x / img->cube_size] == '1')
//	 	return ;
//	 if (img->map[(unsigned int)(img->player.y / img->cube_size)]
//	 	[(unsigned int)(img->player.x -
//                     20 * sin(img->player.angle) / img->cube_size)] != '1')
//	 	img->player.x -= 5 * sin(img->player.angle);
//	 if (img->map[(unsigned int)(img->player.y +
//             20 * cos(img->player.angle)) / img->cube_size]
//	 	[(unsigned int)img->player.x / img->cube_size] != '1')
//	 	img->player.y += 5 * cos(img->player.angle);


	if ((img->map[(unsigned int)(img->player.y + (5 + 3) *
		cos(img->player.angle)) >> 6u][(unsigned int)
		(img->player.x) >> 6u]) != '1')
			img->player.y += 5 * cos(img->player.angle);
		if ((img->map[(unsigned int)(img->player.y) >> 6u]
		[(unsigned int)(img->player.x - (5 + 3) * sin(img->player.angle))
		>> 6u]) != '1')
			img->player.x -= 5 * sin(img->player.angle);
}

static	void	left(t_data *img)
{
//	if (img->map[(unsigned int)(img->player.y / img->cube_size)]
//		[(unsigned int)(img->player.x + 50 * sin(img->player.angle)
//		/ img->cube_size)] == '1' || img->map[(unsigned int)(img->player.y -
//            50 * cos(img->player.angle)) / img->cube_size]
//		[(unsigned int)(img->player.x / img->cube_size)] == '1')
////		return ;
//	if (img->map[(unsigned int)(img->player.y / img->cube_size)]
//		[(unsigned int)(img->player.x +
//		20 * sin(img->player.angle) / img->cube_size)] != '1')
		img->player.x += 5 * sin(img->player.angle);
//	if (img->map[(unsigned int)(img->player.y -
//	    20 * cos(img->player.angle)) / img->cube_size]
//		[(unsigned int)(img->player.x / img->cube_size)] != '1')
		img->player.y -= 5 * cos(img->player.angle);
}

int				key(int keycode, t_data *img)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		up(img);
	else if (keycode == 1)
		down(img);
	else if (keycode == 2)
		right(img);
	else if (keycode == 0)
		left(img);
	else if (keycode == 124)
	{
		img->player.angle += 0.1;
		if (img->player.angle > (M_PI * 2))
			img->player.angle -= M_PI * 2;
	}
	else if (keycode == 123)
	{
		img->player.angle -= 0.1;
		if (img->player.angle < 0)
			img->player.angle += M_PI * 2;
	}
	mlx_destroy_image(img->mlx, img->img);
	func(img);
	return (1);
}
