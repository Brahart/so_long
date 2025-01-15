/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:23:59 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/15 17:43:13 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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

void	ft_win(int moves)
{
	moves++;
	ft_printf(
		"\e[1;32mCongrats !!! You finished the game in : %d moves !!!\n\e[0m",
		moves);
	return ;
}

void	ft_error(const char *str)
{
	if (!str)
		ft_printf("\e[1;31mError ft_error.\n");
	else
		ft_printf("\e[1;31m%s\e[0m", str);
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

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return ;
	if (data->flood[y][x] == '1' || data->flood[y][x] == 'F'
		|| data->flood[y][x] == 'B')
		return ;
	if (data->flood[y][x] == 'C')
		data->content.tmp_c--;
	if (data->flood[y][x] == 'E')
		data->content.tmp_ex = 0;
	if (data->flood[y][x] != 'E')
		data->flood[y][x] = 'F';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
