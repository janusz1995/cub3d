/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:09:37 by drina             #+#    #+#             */
/*   Updated: 2020/08/26 21:09:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*read_file(t_data *img, int fd, char *list)
{
	char	*line;

	line = 0x0;
	while (get_next_line(fd, &line))
	{
		if (check_flags_struct(img))
		{
			if (!(list = split_lines(line, list)))
				img->map = NULL;
		}
		if (!(check_flags_struct(img)))
			check_str(line, img);
		if (img->flag.error)
			errors(img);
	}
	if (!(check_flags_struct(img)))
	{
		img->flag.error = 1;
		errors(img);
	}
	if (!(list = split_lines(line, list)))
		img->map = NULL;
	return (list);
}
