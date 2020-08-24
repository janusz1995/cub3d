/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:44:58 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 22:45:00 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void 	const_param(t_data *img)
{
	img->cube_size = 32;
	img->calc.dis_to_proj = (img->width / 2.0) / tan(M_PI_6); // distance to proection
	img->calc.ang_step = M_PI_3 / img->width;
	img->sprites = NULL;
	img->calc.arr_min_len_wall = (double*)malloc(img->width * sizeof(double));
}
