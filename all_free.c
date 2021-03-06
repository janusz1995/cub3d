/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 23:49:33 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 23:49:34 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_free(t_data *img)
{
	free(img->map);
	free(img->calc.arr_min_len_wall);
	free(img->flood_map);
}
