/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:10:54 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 00:57:27 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_moves(t_data *data)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(data->count);
	str = ft_strjoin("Moves: ", moves);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 50, 10,rgb(29, 29, 134), str);
	free(str);
	free(moves);
}

int	rendered(t_data *data)
{
	rendered_background(data);
	rendered_other(data);
	print_moves(data);
	return (0);
}

void	print_img(t_data *data, t_image img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img.sprite,
		(img.img_width * x), (img.img_height * y));
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
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keyboard_key, data);
	// mlx_loop_hook(data->mlx_ptr, rendered, data);
	mlx_hook(data->mlx_win, 17, 0, end_game, data);
	mlx_hook(data->mlx_win, Expose, ExposureMask, rendered, data);
	mlx_loop(data->mlx_ptr);
	end_game(data);
}
