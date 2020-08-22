
#include "cub3d.h"

void	find_sprites(t_data *img)
{
	int 		i;
	int 		j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == '2')
				add_back_sprite(img, (lstnew((i * img->cube_size), (j * img->cube_size), img->cube_size)));
			j++;
		}
		i++;
	}
}
