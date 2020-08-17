
#include "cub3d.h"

void 	clear_flags(t_data *img)
{
	img->flag.north = 0;
	img->flag.south = 0;
	img->flag.east = 0;
	img->flag.west = 0;
}