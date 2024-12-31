#include "../../include/so_long.h"

void	rendered_enemy(t_data *data)
{
	int	i;
	int	j;
	int	index_ennemy;

	i = 0;
	j = 0;
	index_ennemy = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.enemy)
				init_mouvement_ennemy(data, i, j, index_enemy);
			index_ennemy++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_mouvement_ennemy(t_data *data, int i, int j, int index)
{
	data->ennemy[index].pos.x = j * data->img.img_width;
	data->ennemy[index].pos.y = i * data->img.img_height;
	if (mouvement_width(data, i, j) >= mouvement_height(data, i, j);)
	{
		data->ennemy[index].direction_x = 1;
		data->ennemy[index].direction_y = 0;
	}
	else
	{
		data->ennemy[index].direction_x = 0;
		data->ennemy[index].direction_y = 1;
	}
	data->ennemy[index].speed = 2 + (index % 3);
	print_img(data, data->img.img_enemy, j, i);
}

int	mouvement_height(t_data *data, int x, int y)
{
	int	count_height;

	count_height = 0;
	while (y >= 0)
	{
		if (data->map[x][y] == data->content.space)
		{
			y--;
			count_height++;
		}
		y--
	}
	x += count_height;
	while (x < data->height)
	{
		if (data->map[x][y] == data->content.space)
		{
			y++;
			count_height++;
		}
		y++
	}
	x -= count_height;
	return (count_height);
}


int	mouvement_width(t_data *data, int x, int y)
{
	int	count_width;

	count_width = 0;
	while (x >= 0)
	{
		if (data->map[x][y] == data->content.space)
		{
			x--;
			count_width++;
		}
		x--
	}
	x += count_width;
	while (x < data->width)
	{
		if (data->map[x][y] == data->content.space)
		{
			x++;
			count_width++;
		}
		x++
	}
	x -= count_width;
	return (count_width);
}
