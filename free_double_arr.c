
#include "cub3d.h"

void 	free_double_arr(char **arr)
{
	int count;

	count = 0;
	while (arr[count])
		free(arr[count++]);
	free(arr);
}
