#include "../../include/so_long.h"

void	rendered_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.img_height;
	pos_y = data->pos.y / data->img.img_width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
			ft_printf("step: %d\n", data->count);
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_printf("Congrats !!! You finished the game in : %d moves !!!\n", data->count);
				end(data);
			}
		}
	}
}

void	rendered_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.img_height;
	pos_y = data->pos.y / data->img.img_width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
			ft_printf("step: %d\n", data->count);
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_printf("Congrats !!! You finished the game in : %d moves !!!\n", data->count);
				end(data);
			}
		}
	}
}

void	rendered_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.img_height;
	pos_y = data->pos.y / data->img.img_width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
			ft_printf("step: %d\n", data->count);
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_printf("Congrats !!! You finished the game in : %d moves !!!\n", data->count);
				end(data);
			}
		}
	}
}

void	rendered_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.img_height;
	pos_y = data->pos.y / data->img.img_width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
			ft_printf("step: %d\n", data->count);
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_printf("Congrats !!! You finished the game in : %d moves !!!\n", data->count);
				end(data);
			}
		}
	}
}