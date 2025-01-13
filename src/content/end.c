/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:58:46 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/13 20:04:38 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	end_game(t_data *data)
{
	int		i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		ft_free(data);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_space);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_collectible);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		// mlx_destroy_image(data->mlx_ptr, data->img.img_enemy);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	ft_free(t_data *data)
{
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
}
