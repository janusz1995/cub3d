
#include "cub3d.h"

void		draw_pixel_sprite(t_data *img, int i, int j, double coef)
{
	int	color;

	color = img->sprite.addr[(int)(j * coef) * img->sprite.width + (int)(i * coef) % img->sprite.height];
	if (color > 0)
		my_mlx_pixel_put(img, img->calc.sprite_x + i, img->calc.sprite_y + j, color);
}
