#include "cub3d.h"

void 	move_sprite(t_data *img)
{
	t_sprites *save_head;

	save_head = img->sprites;
	while (save_head != NULL)
	{
		draw_sprite(img, save_head);
		save_head = save_head->next;
	}
}
