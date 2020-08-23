
#include "cub3d.h"

void 	horz_x_and_y(t_data *img)
{
	if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI * 2))
		img->horz_y = (int) (img->player.y / img->cube_size) * img->cube_size - 0.00000000001; //координата точки пересечения с 1 квадратом Y
	else
		img->horz_y = (int) (img->player.y / img->cube_size) * img->cube_size + img->cube_size;
	if (img->player.ang_start > M_PI && img->player.ang_start < (M_PI * 2))
		img->calc.dis_y = img->player.y - img->horz_y;
	else
		img->calc.dis_y = img->horz_y - img->player.y;
	if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI_2)
	{
		if (img->player.ang_start < (M_PI + M_PI_2) && img->player.ang_start > M_PI)
			img->horz_x = img->player.x - img->calc.dis_y * tan((M_PI + M_PI_2) - img->player.ang_start);
		else
			img->horz_x = img->player.x - img->calc.dis_y * tan(img->player.ang_start - M_PI_2);
	}
	else if (img->player.ang_start == (M_PI_2 + M_PI) || img->player.ang_start == M_PI_2)
		img->horz_x = img->player.x;
	else
	{
		if (img->player.ang_start > 0 && img->player.ang_start < M_PI_2)
			img->horz_x = img->calc.dis_y * tan(M_PI_2 - img->player.ang_start) + img->player.x;
		else
			img->horz_x = img->calc.dis_y * tan(img->player.ang_start - (M_PI + M_PI_2)) + img->player.x;
	}
}

double		find_horizontal(t_data *img)
{
	double	horz_dis_y;
	double	horz_dis_x;

	if (img->player.ang_start == M_PI || img->player.ang_start == (M_PI * 2) || img->player.ang_start == 0)
		return (INFINITY);
	else
		horz_x_and_y(img);
	img->calc.dis = 0;
	while (img->horz_y > 0 && img->horz_x > 0 && img->horz_y < 14*img->cube_size && img->horz_x < 35*img->cube_size && img->map[(unsigned int)img->horz_y/img->cube_size][(unsigned int)img->horz_x/img->cube_size] != '1')
		quarters_horz(img);
	if (img->horz_y > 0 && img->horz_x > 0 && img->horz_y < 14*img->cube_size && img->horz_x < 35*img->cube_size && img->map[(unsigned int)img->horz_y/img->cube_size][(unsigned int)img->horz_x/img->cube_size] == '1')
	{
		horz_dis_y = img->player.y - img->horz_y;
		horz_dis_x = img->player.x - img->horz_x;
		img->calc.dis = pow(horz_dis_x, 2) + pow(horz_dis_y, 2);
		return (sqrt(img->calc.dis));
	}
	else
		return (INFINITY);
}
