/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 23:49:47 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 23:49:48 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	check_str(char *str, t_data *img)
{
	int count;

	count = 0;
	while (str[count] == ' ')
		count++;
	if (str[count] == '\n' || str[count] == '\0')
	{
		free(str);
		str = NULL;
	}
	else
	if (ft_isalpha(str[count]))
		parse_line(img, &str[count]);
	else
		img->flag.error = 1;
}
