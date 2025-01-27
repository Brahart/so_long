/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:54 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/27 18:41:51 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	if (!img)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		destroy_image(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		(data->img.img_width * x),
		data->img.img_height * y);
}

void	*load_image(t_data *data, char *path, char *str)
{
	void	*image;

	image = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->img.img_width, &data->img.img_height);
	if (!image)
	{
		ft_printf("\e[1;31mERROR\nProblem with '%s' assets\n\e[0m", str);
		if (data->verif_win == 1)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		destroy_image(data);
	}
	return (image);
}

void	destroy_image(t_data *data)
{
	free_map(data->map);
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
	data->img.img_player = load_image(data, data->img.player,
			"Player");
	data->img.img_wall = load_image(data, data->img.wall,
			"Wall");
	data->img.img_collectible = load_image(data,
			data->img.collectible, "Collectible");
	data->img.img_space = load_image(data, data->img.space,
			"Floor");
	data->img.img_exit = load_image(data, data->img.exit,
			"Exit");
	if (data->content.bad)
		data->img.img_enemy = load_image(data, data->img.enemy,
				"Enemy");
}

void	init_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.img_width),
			(data->height * data->img.img_height), "so_long");
	if (!data->mlx_win)
	{
		ft_error("ERROR\nProblem with allocation of mlx_win\n");
		destroy_image(data);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map_and_exit(data->map);
	}
	data->verif_win = 1;
	mlx_loop_hook(data->mlx_ptr, rendered, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keyboard_key, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, end_game, data);
	mlx_loop(data->mlx_ptr);
	end_game(data);
}
