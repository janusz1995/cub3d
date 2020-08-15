
#include "cub3d.h"

void 				sort_len_list(t_data *img)
{
	t_sprites 		*new_head;
	t_sprites 		*tmp;
	t_sprites 		*max;
	t_sprites 		*head;

	new_head = img->sprites;
	head = new_head;
	while ((lst_size(head)) != lst_size(img->sprites))
	{
		tmp = img->sprites;
		while (tmp != NULL)// до тех пор пока кол-во элементов во новом списке не будет равно в первой списке!!!!!!
		{
			max = img->sprites;
			if (img->sprites->len < img->sprites->next->len)
				max = img->sprites->next;
			tmp = tmp->next;
		}
		if (!head)
			head = max;
		else
			head->next = max;
		head = head->next;
	}
	img->sprites = new_head;
}

int		lst_size(t_sprites *lst)
{
	int count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}