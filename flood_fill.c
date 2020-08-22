
#include "cub3d.h"

void 	flood_fill(t_data *img, int x, int y, char **map, char new_sym)
{
	if (map[y][x] == ' ' || map[y][x] == '\0')
	{
		img->error.no_valid_map = 1;
		errors(img);
	} // error NO VALID MAP
	if (map[y][x] != new_sym && map[y][x] != ' ' && map[y][x] != '\0' && map[y][x] != '1')
	{
		if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			img->error.num_players++;
		map[y][x] = new_sym;

		flood_fill(img, x, y - 1, map, new_sym); // up
		flood_fill(img, x, y + 1, map, new_sym); // down
		flood_fill(img, x + 1, y, map, new_sym); // right
		flood_fill(img, x - 1, y, map, new_sym); // left

	}
}