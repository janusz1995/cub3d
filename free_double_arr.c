/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:30:08 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:30:10 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	free_double_arr(char **arr)
{
	int count;

	count = 0;
	while (arr[count])
		free(arr[count++]);
	free(arr);
}
