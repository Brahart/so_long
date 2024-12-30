/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:23:59 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:18 by asinsard         ###   ########lyon.fr   */
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
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_space);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collectible);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	check_collect(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.collectible)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	keyboard_key(int key, t_data *data)
{
	if (key == XK_Escape)
		end_game(data);
	if (key == XK_w)
		rendered_top(data);
	if (key == XK_s)
		rendered_down(data);
	if (key == XK_a)
		rendered_left(data);
	if (key == XK_d)
		rendered_right(data);
	return (1);
}

void	ft_error(const char *str)
{
	if (!str)
		ft_printf("Error ft_error.\n");
	else
		ft_printf(str);
}

int	is_ber(char *str, const char *ber)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i + j] == ber[j])
		{
			j++;
			if (ber[j] == '\0')
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}
