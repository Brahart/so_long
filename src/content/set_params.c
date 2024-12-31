/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/31 00:16:25 by abrahamsins      ###   ########lyon.fr   */
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
	content->ennemy = 'B';
	content->count_ex = 0;
	content->count_p = 0;
	content->count_c = 0;
}

void	set_assets(t_data *data)
{
	data->img.img_height = 1920;
	data->img.img_width = 1080;
	data->img.space = "assets/floor.xpm";
	data->img.wall = "assets/wall.xpm";
	data->img.ennemy = "assets/ennemy.xpm";
	data->img.collectible = "assets/collectible.xpm";
	data->img.player = "assets/player.xpm";
	data->img.exit = "assets/exit.xpm";
	set_image(&data);

}

void	set_image(t_data *data)
{
	data->img.img_space = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.space,
			&data->img.img_width, &data->img.img_height);
	data->img.img_wall = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.wall,
			&data->img.img_width, &data->img.img_height);
	data->img.img_collectible = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.collectible,
			&data->img.img_width, &data->img.img_height);
	data->img.img_player = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.player,
			&data->img.img_width, &data->img.img_height);
	data->img.img_exit = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.exit,
			&data->img.img_width, &data->img.img_height);
	data->img.img_ennemy = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.ennemy,
			&data->img.img_width, &data->img.img_height);
}
