
#include "cub3d.h"

t_sprites 	*lstnew(int y, int x, int cube_size)
{
	t_sprites 	*list;

	list = (t_sprites*)malloc(sizeof(t_sprites));
	if (!list)
		return (NULL);
	list->x = x + cube_size / 2;
	list->y = y + cube_size / 2;
	list->len = 0;
	list->next = NULL;
	return (list);
}
