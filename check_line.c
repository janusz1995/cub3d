
#include "cub3d.h"

int 	check_line(char *str)
{
	int 	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (ft_isdigit(str[count]))
			count++;
		else
			return (0);
	}
	return (1);
}
