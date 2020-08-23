
#include "cub3d.h"

void 	vert_x_and_y(t_data *img)
{
	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
		img->vert_x = (int) (img->player.x / img->cube_size) * img->cube_size - 0.00000000001;
	else
		img->vert_x = (int) (img->player.x / img->cube_size) * img->cube_size + img->cube_size;
	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
		img->calc.dis_x = img->player.x - img->vert_x;
	else
		img->calc.dis_x = img->vert_x - img->player.x;
	if (img->player.ang_start < (M_PI * 2) && img->player.ang_start > M_PI)
	{
		if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI + M_PI_2))
			img->vert_y = img->player.y - img->calc.dis_x * tan(img->player.ang_start - M_PI);
		else
			img->vert_y = img->player.y - img->calc.dis_x * tan(2 * M_PI - img->player.ang_start);
	}
	else if (img->player.ang_start == (M_PI * 2) || img->player.ang_start == M_PI || img->player.ang_start == 0)
		img->vert_y = img->player.y;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->vert_y = img->player.y + img->calc.dis_x * tan(img->player.ang_start);
		else
			img->vert_y = img->player.y + img->calc.dis_x * tan(M_PI - img->player.ang_start);
	}
}

double 		find_vertical(t_data *img)
{
	double vert_dis_y;
	double vert_dis_x;

	if (img->player.ang_start == (M_PI + M_PI_2) || img->player.ang_start == M_PI_2)
		return (INFINITY);
	else
		vert_x_and_y(img);
	img->calc.dis = 0;
	while (img->vert_y > 0 && img->vert_x > 0 && img->vert_x < 35 * img->cube_size && img->vert_y < 14*img->cube_size && img->map[(unsigned int)img->vert_y/img->cube_size][(unsigned int)img->vert_x/img->cube_size] != '1')
		quarters_vert(img);
	if (img->vert_y > 0 && img->vert_x > 0 && img->vert_x < 35 * img->cube_size && img->vert_y < 14*img->cube_size && img->map[(unsigned int)img->vert_y/img->cube_size][(unsigned int)img->vert_x/img->cube_size] == '1')
	{
		vert_dis_y = img->player.y - img->vert_y;
		vert_dis_x = img->player.x - img->vert_x;
		img->calc.dis = pow(vert_dis_x, 2) + pow(vert_dis_y, 2);
		return (sqrt(img->calc.dis));
	}
	else
		return (INFINITY);
}
