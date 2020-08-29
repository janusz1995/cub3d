/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:26:21 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:26:23 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_num_lines(char **str, int c)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	if (count == c)
		return (1);
	else
		return (0);
}
