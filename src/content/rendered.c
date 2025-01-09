/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:18:32 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/09 18:23:47 by asinsard         ###   ########lyon.fr   */
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
			if (data->map[i][j] == data->content.enemy)
				print_img(data, data->img.img_enemy, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	rendered_exit(t_data *data, int j, int i)
{
	if (check_collect(data))
		print_img(data, data->img.img_exit, j, i);
	else
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		data->img.exit = EXIT_OPEN;
		data->img.img_exit = mlx_xpm_file_to_image(
				data->mlx_ptr, data->img.exit,
				&data->img.img_width, &data->img.img_height);
		print_img(data, data->img.img_exit, j, i);
	}
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
			{
				data->pos.x = j * data->img.img_width;
				data->pos.y = i * data->img.img_height;
				print_img(data, data->img.img_player, j, i);
			}
			if (data->map[i][j] == data->content.collectible)
				print_img(data, data->img.img_collectible, j, i);
			if (data->map[i][j] == data->content.exit)
				rendered_exit(data, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_moves(t_data *data)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(data->count);
	if (!moves)
	{
		ft_error("ERROR with itoa for display moves\n");
		end_game(data);
	}
	str = ft_strjoin("Moves: ", moves);
	if (!str)
	{
		ft_error("ERROR for join the strings of the moves display\n");
		end_game(data);
	}
	mlx_string_put(data->mlx_ptr, data->mlx_win, 60, 80, 0x0000FF, str);
	free(str);
	free(moves);
}

int	rendered(t_data *data)
{
	rendered_background(data);
	print_moves(data);
	rendered_other(data);
	return (0);
}
