#include "cub3d.h"

int 	key(int keycode, t_data *img)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126) // up
	{
		if (img->map[(unsigned int)(img->player.y + 5 * sin(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
			img->player.y += 5 * sin(img->player.angle);
		if (img->map[(unsigned int)img->player.y/img->cube_size][(unsigned int)(img->player.x + 5 * cos(img->player.angle))/img->cube_size] != '1')
			img->player.x += 5 * cos(img->player.angle);
	}
	else if (keycode == 125) // down
	{
		if (img->map[(unsigned int)(img->player.y - 5 * sin(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
			img->player.y -= 5 * sin(img->player.angle);
		if (img->map[(unsigned int)img->player.y/img->cube_size][(unsigned int)(img->player.x - 5 * cos(img->player.angle))/img->cube_size] != '1')
			img->player.x -= 5 * cos(img->player.angle);
	}
	else if (keycode == 2) // right
	{
		//if (img->map[(unsigned int)(img->player.y/img->cube_size)][(unsigned int)(img->player.x - 5 * sin(img->player.angle)/img->cube_size)] != '1')
		img->player.x -= 5 * sin(img->player.angle);
		//if (img->map[(unsigned int)(img->player.y + 5 * cos(img->player.angle))/img->cube_size][(unsigned int)img->player.x/img->cube_size] != '1')
		img->player.y += 5 * cos(img->player.angle);
	}
	else if (keycode == 0) // left
	{
		//if (img->map[(unsigned int)(img->player.y/img->cube_size)][(unsigned int)(img->player.x + 5 * sin(img->player.angle)/img->cube_size)] != '1')
		img->player.x += 5 * sin(img->player.angle);
		//if (img->map[(unsigned int)(img->player.y - 5 * cos(img->player.angle))/img->cube_size][(unsigned int)(img->player.x/img->cube_size)] != '1')
		img->player.y -= 5 * cos(img->player.angle);
	}
	else if (keycode == 124) // right
	{
		img->player.angle += 0.1;
		if (img->player.angle > (M_PI * 2))
			img->player.angle -= M_PI * 2;
	}
	else if (keycode == 123) // left
	{
		img->player.angle -= 0.1;
		if (img->player.angle < 0)
			img->player.angle += M_PI * 2;
	}

	mlx_destroy_image(img->mlx, img->img);
	func(img);
	return (1);
}
