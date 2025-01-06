/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:49:50 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/06 20:11:05 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		y--;
	}
	x += count_height;
	while (x < data->height)
	{
		if (data->map[x][y] == data->content.space)
		{
			y++;
			count_height++;
		}
		y++;
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
		x--;
	}
	x += count_width;
	while (x < data->width)
	{
		if (data->map[x][y] == data->content.space)
		{
			x++;
			count_width++;
		}
		x++;
	}
	x -= count_width;
	return (count_width);
}

void	init_mouvement_ennemy(t_data *data, int i, int j, int index)
{
	data->enemy[index].pos.x = j * data->img.img_width;
	data->enemy[index].pos.y = i * data->img.img_height;
	if (mouvement_width(data, i, j) >= mouvement_height(data, i, j))
	{
		data->enemy[index].direction_x = 1;
		data->enemy[index].direction_y = 0;
	}
	else
	{
		data->enemy[index].direction_x = 0;
		data->enemy[index].direction_y = 1;
	}
	data->enemy[index].speed = 2 + (index % 3);
	print_img(data, data->img.img_enemy, j, i);
}

void	rendered_enemy(t_data *data)
{
	int	i;
	int	j;
	int	index_enemy;

	i = 0;
	j = 0;
	index_enemy = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.enemy)
				print_img(data, data->img.img_enemy, j, i);
				// init_mouvement_ennemy(data, i, j, index_enemy);
			index_enemy++;
			j++;
		}
		j = 0;
		i++;
	}
}
