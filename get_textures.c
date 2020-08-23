
#include "cub3d.h"

static void		get_addr_textures(t_data *img)
{
	img->txt1.addr = (int*)mlx_get_data_addr(img->txt1.txt,
						&img->txt1.bits_per_pixel, &img->txt1.line_length,
							&img->txt1.endian);
	img->txt2.addr = (int*)mlx_get_data_addr(img->txt2.txt,
						&img->txt2.bits_per_pixel, &img->txt2.line_length,
							&img->txt2.endian);
	img->txt3.addr = (int*)mlx_get_data_addr(img->txt3.txt,
						&img->txt3.bits_per_pixel, &img->txt3.line_length,
							&img->txt3.endian);
	img->txt4.addr = (int*)mlx_get_data_addr(img->txt4.txt,
						&img->txt1.bits_per_pixel, &img->txt4.line_length,
							&img->txt4.endian);
	img->sprite.addr = (int*)mlx_get_data_addr(img->sprite.txt,
						&img->sprite.bits_per_pixel, &img->sprite.line_length,
							&img->sprite.endian);
}

void			get_textures(t_data *img)
{
	img->txt1.txt = mlx_xpm_file_to_image(img->mlx,
					img->path.north, &img->txt1.width, &img->txt1.height);
	img->txt2.txt = mlx_xpm_file_to_image(img->mlx,
					img->path.south, &img->txt2.width, &img->txt2.height);
	img->txt3.txt = mlx_xpm_file_to_image(img->mlx,
					img->path.west, &img->txt3.width, &img->txt3.height);
	img->txt4.txt = mlx_xpm_file_to_image(img->mlx,
					img->path.east, &img->txt4.width, &img->txt4.height);
	img->sprite.txt = mlx_xpm_file_to_image(img->mlx,
					img->path.sprite, &img->sprite.width, &img->sprite.height);
	if (img->txt4.txt != NULL && img->txt3.txt != NULL
		&& img->txt2.txt != NULL && img->txt1.txt != NULL)
		get_addr_textures(img);
	else
		img->error.textures = 1;
}
