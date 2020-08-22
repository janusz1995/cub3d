
#include "cub3d.h"

int 	check_num_lines(char **str, int c)
{
	int 	count;

	count = 0;
	while (str[count])
		count++;

	if (count == c)
		return (1);
	else
		return (0);
}
