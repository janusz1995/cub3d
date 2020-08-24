/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:25:20 by drina             #+#    #+#             */
/*   Updated: 2020/08/24 12:25:24 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static	void	pixels(t_data *img, int fd)
{
	int		i;
	int		j;
	int		color;

	i = img->height - 1;
	while (0 <= i)
	{
		j = 0;
		while (j < img->width)
		{
			color = get_color(img, j, i);
			write(fd, &color, 3);
			j++;
		}
		i--;
	}
}

static	void	header_bmp(t_data *img, int fd, int filesize)
{
	unsigned	char	arr[54];
	int					count;

	count = 0;
	while (count < 54)
		arr[count++] = 0;
	arr[0] = 'B';
	arr[1] = 'M';
	int_to_char(filesize, &arr[2]);
	arr[10] = (unsigned char)(54);
	arr[14] = (unsigned char)(40);
	int_to_char(img->width, &arr[18]);
	int_to_char(img->height, &arr[22]);
	arr[26] = (unsigned char)(1);
	arr[28] = (unsigned char)(24);
	write(fd, arr, 54);
}

int				save_screenshot(t_data *img)
{
	int		fd;
	int		filesize;

	filesize = ((img->height * img->width) * 4) + 54;
	if (((fd = open("screenshot.bmp", O_WRONLY | O_CREAT
				| O_TRUNC | O_APPEND, 0666))) < 0)
		return (0);
	header_bmp(img, fd, filesize);
	pixels(img, fd);
	close(fd);
	return (1);
}
