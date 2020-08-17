
#include "cub3d.h"

int 	check_direction_player(int sym, t_data *img)
{
	if (sym == 'N' || sym == 'S' || sym == 'W' || sym == 'E')
	{
		img->player.ang_fov = M_PI / 3;
		if (sym == 'E')
			img->player.angle = 0; //  0/360
		else if (sym == 'S')
			img->player.angle = M_PI_2; // 90
		else if (sym == 'W')
			img->player.angle = M_PI; // 180
		else
			img->player.angle = M_PI_2 * 3; // 270
		return (1);
	}
	else
		return (0);
}
