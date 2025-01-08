/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:54 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 19:48:13 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	keyboard_key(int key, t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.img_height;
	pos_y = data->pos.y / data->img.img_width;
	if (key == XK_Escape)
		end_game(data);
	if (key == XK_w || key == XK_Up)
		rendered_top(data, pos_y, pos_x);
	if (key == XK_s || key == XK_Down)
		rendered_down(data, pos_y, pos_x);
	if (key == XK_a || key == XK_Left)
		rendered_left(data, pos_y, pos_x);
	if (key == XK_d || key == XK_Right)
		rendered_right(data, pos_y, pos_x);
	return (1);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		(data->img.img_width * x),
		data->img.img_height * y);
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
	data->img.img_enemy = mlx_xpm_file_to_image(
			data->mlx_ptr, data->img.enemy,
			&data->img.img_width, &data->img.img_height);
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
