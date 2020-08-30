/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:28:19 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:28:21 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	next_errors(t_data *img)
{
	if (img->error.no_valid_map == 1)
	{
		ft_putstr_fd("Error:\nNo Valid Map\n", 1);
		all_free(img);
		exit(0);
	}
	if (img->error.textures == 1)
	{
		ft_putstr_fd("Error:\nFailed to get Textures\n", 1);
		all_free(img);
		exit(0);
	}
}

void			errors(t_data *img)
{
	if (img->error.no_valid_color == 1)
	{
		ft_putstr_fd("Error:\nNo Valid Color\n", 1);
		all_free(img);
		exit(0);
	}
	if (img->flag.error == 1)
	{
		ft_putstr_fd("Error:\nNo Valid Parameters\n", 1);
		all_free(img);
		exit(0);
	}
	if (img->error.num_players != 1)
	{
		ft_putstr_fd("Error:\nThe Number of Players is Not equal to 1\n", 1);
		all_free(img);
		exit(0);
	}
	next_errors(img);
}
