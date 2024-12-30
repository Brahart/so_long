/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 01:42:06 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_content(t_cont *content)
{
	content->wall = '1';
	content->space = '1';
	content->player = 'P';
	content->exit = 'E';
	content->collectible = 'C';
	content->count_e = 0;
	content->count_p = 0;
	content->count_c = 0;
}
void	set_image(t_data *data)
{
	data->img.img_height = 100;
	data->img.img_width = 100;
	data->img.space = "";
	data->img.wall = "";
	data->img.collectible = "";
	data->img.player = "";
	data->img.exit = "";
	data->img.img_space = mlx_xpm_file_to_image(data->mlx_ptr, data->img.space, 
												&data->img.img_width, &data->img.img_height);
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
												&data->img.img_width, &data->img.img_height);
	data->img.img_collectible = mlx_xpm_file_to_image(data->mlx_ptr, data->img.collectible,
												&data->img.img_width, &data->img.img_height);
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, data->img.player,
												&data->img.img_width, &data->img.img_height);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
												&data->img.img_width, &data->img.img_height);
}
