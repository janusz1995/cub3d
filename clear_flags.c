
#include "cub3d.h"

void 	clear_flags(t_data *img)
{
	img->flag.north = 0;
	img->flag.south = 0;
	img->flag.east = 0;
	img->flag.west = 0;
}

void 	void_flags_struct(t_data *img)
{
	img->flag.sprite = 0;
	img->flag.north = 0;
	img->flag.south = 0;
	img->flag.west = 0;
	img->flag.east = 0;
	img->flag.floor = 0;
	img->flag.sky = 0;
	img->flag.error = 0;
	img->error.num_players = 0;
}