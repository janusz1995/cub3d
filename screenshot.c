/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 00:02:18 by drina             #+#    #+#             */
/*   Updated: 2020/08/25 00:02:19 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screenshot(t_data *img)
{
	if (img->flag.screenshot)
	{
		if (!(save_screenshot(img)))
			ft_putstr_fd("Error:\nFailed to create screenshot\n",1);
		exit(0);
	}
}
