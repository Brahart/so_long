/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:54 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/14 21:11:44 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		(data->img.img_width * x),
		data->img.img_height * y);
}

void	*load_image(void *mlx_ptr, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, path, width, height));
}

void	destroy_image(t_data *data)
{
	data->verif = 0;
	free_map(data);
	if (!data->img.img_player
		&& ft_strncmp(data->img.player, PLAYER_DOWN, 1024))
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->img.img_space)
		mlx_destroy_image(data->mlx_ptr, data->img.img_space);
	if (data->img.img_wall)
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	if (data->img.img_collectible)
		mlx_destroy_image(data->mlx_ptr, data->img.img_collectible);
	if (data->img.img_player)
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	if (data->img.img_exit)
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	if (data->img.img_enemy)
		mlx_destroy_image(data->mlx_ptr, data->img.img_enemy);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	set_image(t_data *data)
{
	data->img.img_space = NULL;
	data->img.img_wall = NULL;
	data->img.img_collectible = NULL;
	data->img.img_player = NULL;
	data->img.img_exit = NULL;
	data->img.img_enemy = NULL;
	if (!(data->img.img_player = load_image(data->mlx_ptr, data->img.player,
				&data->img.img_width, &data->img.img_height))
		|| !(data->img.img_wall = load_image(data->mlx_ptr, data->img.wall,
				&data->img.img_width, &data->img.img_height))
		|| !(data->img.img_collectible = load_image(
				data->mlx_ptr, data->img.collectible,
				&data->img.img_width, &data->img.img_height))
		|| !(data->img.img_space = load_image(data->mlx_ptr, data->img.space,
				&data->img.img_width, &data->img.img_height))
		|| !(data->img.img_exit = load_image(data->mlx_ptr, data->img.exit,
				&data->img.img_width, &data->img.img_height))
		|| !(data->img.img_enemy = load_image(data->mlx_ptr, data->img.enemy,
				&data->img.img_width, &data->img.img_height)))
	{
		ft_error("ERROR\nProblem with assets's path or name");
		destroy_image(data);
	}
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
