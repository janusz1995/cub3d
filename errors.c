
#include "cub3d.h"

void 	errors(t_data *img)
{
	if (img->error.no_valid_map == 1)
	{
		ft_putstr_fd("No Valid Map\n", 1);
		exit(0);
	}
	if (img->error.num_players != 1)
	{
		ft_putstr_fd("the number of players is not correct\n", 1);
		exit(0);
	}
}