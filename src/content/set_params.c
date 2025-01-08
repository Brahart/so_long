/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/07 23:17:17 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_content(t_cont *content)
{
	content->wall = '1';
	content->space = '0';
	content->player = 'P';
	content->exit = 'E';
	content->collectible = 'C';
	content->enemy = 'B';
	content->count_ex = 0;
	content->count_p = 0;
	content->count_c = 0;
	content->count_en = 0;
}

void	set_assets(t_data *data)
{
	data->floor = set_sprites(data->mlx_ptr, FLOOR, data);
	data->wall = set_sprites(data->mlx_ptr, WALL, data);
	data->enemy = set_sprites(data->mlx_ptr, ENEMY, data);
	data->collectible = set_sprites(data->mlx_ptr, COLLECTIBLE, data);
	data->exit = set_sprites(data->mlx_ptr, EXIT, data);
	data->exit_open = set_sprites(data->mlx_ptr, EXIT_OPEN, data);
	data->player_up = set_sprites(data->mlx_ptr, PLAYER_UP, data);
	data->player_down = set_sprites(data->mlx_ptr, PLAYER_DOWN, data);
	data->player_left = set_sprites(data->mlx_ptr, PLAYER_LEFT, data);
	data->player_right = set_sprites(data->mlx_ptr, PLAYER_RIGHT, data);
}

t_image	set_sprites(void *mlx_ptr, char *xpm, t_data *data)
{
	t_image	image;
	
	image.img_height = IMG_HEIGHT;
	image.img_width = IMG_WIDTH;
	image.sprite = mlx_xpm_file_to_image(mlx_ptr, xpm, &image.img_width, &image.img_height);
	return (image);
}

void	ft_win(int moves)
{
	ft_printf(
		"\e[1;32mCongrats !!! You finished the game in : %d moves !!!\n",
		moves);
	return ;
}
