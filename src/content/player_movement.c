/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:13:52 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/14 20:48:06 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	player_rend(t_data *data, int y, int x, char *sprite)
{
	data->img.player = sprite;
	set_image(data);
	if (data->map[y][x] != data->content.wall)
	{
		if (data->map[y][x] == data->content.enemy)
		{
			ft_printf("\e[1;31mYOU LOOSE\n\e[0m");
			end_game(data);
		}
		else if (data->pos.y > 0 && data->pos.x > 0
			&& !(data->map[y][x] == data->content.exit))
		{
			data->map[y][x] = data->content.player;
			data->map[data->pos.y][data->pos.x] = data->content.space;
			data->count++;
		}
		else if (data->map[y][x] == data->content.exit
				&& check_collect(data) == 0)
		{
			ft_win(data->count);
			end_game(data);
		}
		else
			return ;
	}
}

int	keyboard_key(int key, t_data *data)
{
	data->x = data->pos.x / data->img.img_height;
	data->y = data->pos.y / data->img.img_width;
	data->pos.x = data->x;
	data->pos.y = data->y;
	if (key == XK_Escape)
		end_game(data);
	if (data->pos.x && data->pos.y && (key == XK_w || key == XK_Up
			|| key == XK_s || key == XK_Down || key == XK_a || key == XK_Left
			|| key == XK_d || key == XK_Right))
	{
		ft_free(data);
		if ((key == XK_w || key == XK_Up))
			player_rend(data, data->y - 1, data->x, PLAYER_UP);
		if ((key == XK_s || key == XK_Down))
			player_rend(data, data->y + 1, data->x, PLAYER_DOWN);
		if ((key == XK_d || key == XK_Right))
			player_rend(data, data->y, data->x + 1, PLAYER_RIGHT);
		if ((key == XK_a || key == XK_Left))
			player_rend(data, data->y, data->x - 1, PLAYER_LEFT);
	}
	else
		ft_error("ERROR\n Bad key(s) press\n");
	return (0);
}
