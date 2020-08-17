
#include "cub3d.h"

void 				sort_len_list(t_data *img)
{
	t_sprites	*tmp;
	int 		flag;
	
	flag = 1;
	while (flag)
	{
		flag = 0;
		tmp = img->sprites;
		while (tmp->next != NULL)
		{
			if (tmp->len < tmp->next->len)
			{
				swap_two_sprites(&(img->sprites), tmp, tmp->next);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}

/// Swap 2 element in list

void 	swap_two_sprites(t_sprites **head, t_sprites *one, t_sprites *two)
{
	t_sprites 	*tmp;
	t_sprites	*root;

	root = *head;
	if (root == one)
	{
		tmp = two->next;
		two->next = one;
		one->next = tmp;
		(*head) = two;
	}
	else
	{
		while (root->next != one)
			root = root->next;

		tmp = two->next;
		two->next = one;
		one->next = tmp;
		root->next = two;
	}
}