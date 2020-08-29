/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 23:49:18 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 23:49:20 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_argv(int argc, char **argv, t_data *img)
{
	int		count;

	count = ft_strlen(argv[1]);
	count--;
	if (argv[1][count] != 'b' && argv[1][count - 1] != 'u' &&
		argv[1][count - 2] != 'c' && argv[1][count - 3] != '.')
	{
		ft_putstr_fd("Error:\nInvalid file name\n", 1);
		exit(0);
	}
	if (argc == 3 && argv[2][0] == '-' && argv[2][1] == '-' &&
		argv[2][2] == 's' && argv[2][3] == 'a' &&
		argv[2][4] == 'v' && argv[2][5] == 'e' && argv[2][6] == '\0')
		img->flag.screenshot = 1;
	else if (argc == 3)
	{
		ft_putstr_fd("Error:\nInvalid file name\n", 1);
		exit(0);
	}
}
