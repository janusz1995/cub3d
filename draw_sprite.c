
#include "cub3d.h"

void 	draw_sprite(t_data *img, t_sprites *tmp)
{
	int 	sprite_h;
	int 	x;
	int		y;
	double  coef;

	tmp->len = sqrt(pow(tmp->x - img->player.x, 2) + pow(tmp->y - img->player.y, 2));
	sprite_h = (int)((img->calc.dis_to_proj / (tmp->len * img->cube_size) * img->height));
	img->calc.sprite_dir = atan2((tmp->y - img->player.y), (tmp->x - img->player.x));
	coef = 64.0 / sprite_h;
	while (img->calc.sprite_dir - img->player.angle >  M_PI) img->calc.sprite_dir -= 2*M_PI;
	while (img->calc.sprite_dir - img->player.angle < -M_PI) img->calc.sprite_dir += 2*M_PI;

	img->calc.sprite_dir = img->calc.sprite_dir - img->player.angle;
	img->calc.sprite_x = img->calc.sprite_dir * (img->width/2) / (M_PI / 6) + img->width/2 - sprite_h/2;
	img->calc.sprite_y = img->height/2 - sprite_h/2;
	y = 0;
	while (y < sprite_h)
	{
		x = 0;
		while (x < sprite_h)
		{
			if (img->calc.sprite_x + y < img->width && y + img->calc.sprite_x >= 0 && img->calc.arr_min_len_wall[(int)(img->calc.sprite_x + y)] > tmp->len)
				draw_pixel_sprite(img, y, x, coef);
			x++;
		}
		y++;
	}
}
