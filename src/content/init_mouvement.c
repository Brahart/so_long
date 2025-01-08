/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:13:52 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 00:59:26 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	rendered_move(t_data *data, int y, int x, int render)
{
	if (data->map[y][x] == data->content.wall)
		return ;
	if (data->map[y][x] == data->content.collectible)
		data->content.count_c--;
	if (data->map[y][x] == data->content.exit && data->content.count_c == 0)
			end_game(data);
	if (data->map[y][x] == data->content.exit && data->content.count_c != 0)
		return ;
	if (data->map[y][x] == data->content.enemy)
		end_game(data);
	data->map[data->player.pos.y][data->player.pos.x] = data->content.space;
	data->map[y][x] = data->content.player;
	data->player.pos.x = x;
	data->player.pos.y = y;
	data->count++;
	data->player_render = render;
	rendered(data);
}

void	rendered_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->content.wall)
				print_img(data, data->wall, x, y);
			if (data->map[y][x] == data->content.space)
				print_img(data, data->floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	rendered_player(t_data *data, int x, int y)
{
	if (data->player_render == UP)
		print_img(data, data->player_up, x, y);
	if (data->player_render == DOWN)
		print_img(data, data->player_down, x, y);
	if (data->player_render == LEFT)
		print_img(data, data->player_left, x, y);
	if (data->player_render == RIGHT)
		print_img(data, data->player_right, x, y);
}

void	rendered_other(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->content.player)
				rendered_player(data, data->img.img_player, x, y);
			if (data->map[y][x] == data->content.collectible)
				print_img(data, data->collectible, x, y);
			if (data->map[y][x] == data->content.exit)
			{
				if (data->content.count_c)
					print_img(data, data->exit, x, y);
				else
					print_img(data, data->exit_open, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
