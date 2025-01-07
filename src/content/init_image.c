/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:54 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/07 18:34:27 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	rendered_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.wall)
				print_img(data, data->img.img_wall, j, i);
			if (data->map[i][j] == data->content.space)
				print_img(data, data->img.img_space, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

/* void	rendered_player(t_data *data, int i, int j)
{
	data->pos.x = j * data->img.img_width;
	data->pos.y = i * data->img.img_height;
	if (data->player.pos.up)
	{
		data->img.img_player = "assets/player/player_up.xpm";
		data->player.pos.up = 0;
	}
	if (data->player.pos.down)
	{
		data->img.img_player = "assets/player/player_down.xpm";
		data->player.pos.down = 0;
	}
	if (data->player.pos.left)
	{
		data->img.img_player = "assets/player/player_left.xpm";
		data->player.pos.left = 0;
	}
	if (data->player.pos.right)
	{
		data->img.img_player = "assets/player/player_right.xpm";
		data->player.pos.right = 0;
	}
	print_img(data, data->img.img_player, j, i);
}

void	rendered_other(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.player)
				rendered_player(data, i, j);
			if (data->map[i][j] == data->content.collectible)
				print_img(data, data->img.img_collectible, j, i);
			if (data->map[i][j] == data->content.exit)
			{
				if (data->content.count_c == 0)
					data->img.img_exit = "assets/exit_open";
				print_img(data, data->img.img_exit, j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
} */

void	rendered_other(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.player)
			{
				data->pos.x = j * data->img.img_width;
				data->pos.y = i * data->img.img_height;
				print_img(data, data->img.img_player, j, i);
			}
			if (data->map[i][j] == data->content.collectible)
				print_img(data, data->img.img_collectible, j, i);
			if (data->map[i][j] == data->content.exit)
				print_img(data, data->img.img_exit, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

int	rendered(t_data *data)
{
	t_enemy	*enemy;
	
	enemy = NULL;
	rendered_background(data);
	rendered_other(data);
	if (data->content.count_en)
	{
		enemy = malloc(sizeof(t_enemy) * data->content.count_en);
		rendered_enemy(data);
	}
	return (0);
}

void	init_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.img_width),
			(data->height * data->img.img_height), "so_long");
	if (!data->mlx_win)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, rendered, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keyboard_key, data);
	mlx_hook(data->mlx_win, 17, 0, end_game, data);
	mlx_loop(data->mlx_ptr);
	end_game(data);
}
