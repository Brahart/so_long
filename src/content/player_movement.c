/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:13:52 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/10 16:52:15 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	rendered_top(t_data *data, int pos_y, int pos_x)
{
	data->img.player = PLAYER_UP;
	set_image(data);
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y - 1][pos_x] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n");
			end_game(data);
		}
		else if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_win(data->count);
				end_game(data);
			}
		}
	}
}

void	rendered_down(t_data *data, int pos_y, int pos_x)
{
	data->img.player = PLAYER_DOWN;
	set_image(data);
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y + 1][pos_x] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n");
			end_game(data);
		}
		else if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_win(data->count);
				end_game(data);
			}
		}
	}
}

void	rendered_right(t_data *data, int pos_y, int pos_x)
{
	data->img.player = PLAYER_RIGHT;
	set_image(data);
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x + 1] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n");
			end_game(data);
		}
		else if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_win(data->count);
				end_game(data);
			}
		}
	}
}

void	rendered_left(t_data *data, int pos_y, int pos_x)
{
	data->img.player = PLAYER_LEFT;
	set_image(data);
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x - 1] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n");
			end_game(data);
		}
		else if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count++;
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_win(data->count);
				end_game(data);
			}
		}
	}
}

void	player_rend(t_data *data, int pos_y, int pos_x, char *sprite)
{
	data->img.player = sprite;
	set_image(data);
	if (data->map[pos_y][pos_x] != data->content.wall)
	{
		if (data->map[pos_y][pos_x] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n");
			end_game(data);
		}
		else if (!(data->map[pos_y][pos_x] == data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.player;
			data->map[data->pos.y][data->pos.x] = data->content.space;
			data->count++;
		}
		else
		{
			if (check_collect(data) == 0)
			{
				ft_win(data->count);
				end_game(data);
			}
		}
	}
}
