/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 19:21:26 by asinsard         ###   ########lyon.fr   */
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
	data->img.img_height = 64;
	data->img.img_width = 64;
	data->img.space = FLOOR;
	data->img.wall = WALL;
	data->img.enemy = ENEMY;
	data->img.collectible = COLLECTIBLE;
	data->img.player = PLAYER_DOWN;
	data->img.exit = EXIT;
	set_image(data);
}
