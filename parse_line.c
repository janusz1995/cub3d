#include "cub3d.h"

void	parse_line(t_data *img, char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'R' && str[i + 1] == ' ')
		fill_width_and_height(img, str);
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		fill_side(img, str, &img->path.west, &img->flag.west);
	else if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		fill_side(img, str, &img->path.north, &img->flag.north);
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		fill_side(img, str, &img->path.south, &img->flag.south);
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		fill_side(img, str, &img->path.east, &img->flag.east);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		fill_side(img, str, &img->path.sprite, &img->flag.sprite);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		fill_color(str, &img->color_floor, img, &img->flag.floor);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		fill_color(str, &img->color_sky, img, &img->flag.sky);
	else
		img->flag.error = 1;
}
