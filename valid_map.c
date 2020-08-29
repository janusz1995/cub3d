/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:52:47 by drina             #+#    #+#             */
/*   Updated: 2020/08/26 15:52:50 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_map(char *str, t_data *img)
{
	int		count;
	int		i;

	count = 0;
	while (!(ft_isdigit(str[count])))
		count++;
	while (str[count])
	{
		if (str[count] == '\n')
		{
			count++;
			i = count;
			while (str[i] == ' ')
				i++;
			if (str[i++] == '\n')
			{
				while (str[i] == '\n')
					i++;
				if (str[i] != '\0')
					img->error.no_valid_map = 1;
			}
		}
		count++;
	}
}
