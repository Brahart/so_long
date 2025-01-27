/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/27 18:11:02 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_content(t_data *data)
{
	data->content.wall = '1';
	data->content.space = '0';
	data->content.player = 'P';
	data->content.exit = 'E';
	data->content.collectible = 'C';
	data->content.enemy = 'B';
	data->content.count_ex = 0;
	data->content.count_p = 0;
	data->content.count_c = 0;
	data->content.bad = 0;
	data->pos.x = 0;
	data->pos.y = 0;
}

void	check_player_l_and_r(t_data *data)
{
	data->img.player = PLAYER_LEFT;
	data->img.img_player = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.player,
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_player)
	{
		ft_error("ERROR\nProblem with dynamic assets 'Player_left'\n");
		ft_fail(data);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = PLAYER_RIGHT;
	data->img.img_player = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.player,
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_player)
	{
		ft_error("ERROR\nProblem with dynamic assets 'Player_right'\n");
		ft_fail(data);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
}

void	check_assets(t_data	*data)
{
	check_player_l_and_r(data);
	data->img.player = PLAYER_UP;
	data->img.img_player = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.player,
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_player)
	{
		ft_error("ERROR\nProblem with dynamic assets 'Player_up'\n");
		ft_fail(data);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.img_player = NULL;
	data->img.player = PLAYER_DOWN;
	data->img.exit = EXIT_OPEN;
	data->img.img_exit = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.exit,
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_exit)
	{
		ft_error("ERROR\nProblem with dynamic assets 'Exit_open'\n");
		ft_fail(data);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	data->img.exit = EXIT;
}

void	set_assets(t_data *data)
{
	data->verif_win = 0;
	data->img.img_height = 64;
	data->img.img_width = 64;
	data->img.space = FLOOR;
	data->img.wall = WALL;
	data->img.enemy = ENEMY;
	data->img.collectible = COLLECTIBLE;
	data->img.player = PLAYER_DOWN;
	data->img.exit = EXIT;
	if (!data->img.space || !data->img.wall || !data->img.enemy
		|| !data->img.exit || !data->img.player)
	{
		ft_error("ERROR with Floor .xpm");
		end_game(data);
	}
	check_assets(data);
	set_image(data);
}

void	init_mlx_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_error("ERROR\nProblem with allocation of mlx_ptr\n");
		free_map_and_exit(data->map);
	}
}
