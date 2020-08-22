
#include "cub3d.h"

void	add_back_sprite(t_data *img, t_sprites *new)
{
	t_sprites 	*save_head;

	save_head = img->sprites;
	if (save_head == NULL)
		img->sprites = new;
	else
	{
		while (save_head->next != NULL)
			save_head = save_head->next;
		save_head->next = new;
	}
}
