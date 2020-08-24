/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:45:08 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 22:45:10 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char 	*split_lines(char *line, char *list)
{
	char *tmp;

	tmp = list;
	if (!(list = ft_strjoin(list, line)))
		return (NULL);
	free(tmp);
	tmp = list;
	if (!(list = ft_strjoin(list, "\n")))
		return (NULL);
	free(tmp);
	free(line);
	return (list);
}
