/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:31 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/27 18:50:38 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_content(t_data *data)
{
	data->y = 0;
	data->x = 0;
	while (data->map[data->y])
	{
		while (data->map[data->y][data->x])
		{
			if (data->map[data->y][data->x] == data->content.player)
			{
				data->content.count_p += 1;
				data->pos.y = data->y;
				data->pos.x = data->x;
			}
			if (data->map[data->y][data->x] == data->content.exit)
				data->content.count_ex += 1;
			if (data->map[data->y][data->x] == data->content.collectible)
				data->content.count_c += 1;
			if (data->map[data->y][data->x] == data->content.enemy)
				data->content.bad += 1;
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
}

int	check_content_map(char *line, t_cont content)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (content.count_p > 1)
			return (ft_error("ERROR\nToo many PLAYER\n"), 0);
		if (content.count_ex > 1)
			return (ft_error("ERROR\nToo many EXIT\n"), 0);
		if ((line[i] != content.wall) && (line[i] != content.space)
			&& (line[i] != content.player) && (line[i] != content.exit)
			&& (line[i] != content.collectible) && (line[i] != content.enemy))
		{
			ft_error("ERROR\nThe map contains unknown arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_column(char *line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i > 60)
	{
		ft_error("ERROR\nToo much column for the map\n");
		return (0);
	}
	if (line[0] != wall || line[i - 1] != wall)
	{
		ft_error("ERROR\nThe map must be surrounded by walls\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	check_line(char *line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	if (i > 32)
	{
		ft_error("ERROR\nToo much line for the map\n");
		return (0);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
		{
			ft_error("ERROR\nThe map is not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_is_rectangle(char **map)
{
	int			i;
	int			j;
	int			count;
	int			line;

	i = 0;
	j = 0;
	count = 0;
	line = 0;
	while (map[i][count])
		count++;
	while (map[line])
		line++;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j != count)
			return (ft_error("ERROR\nThe line doesn't have same length\n"), 0);
		i++;
		if (line == j)
			return (ft_error("ERROR\nThe map must be a rectangle\n"), 0);
		j = 0;
	}
	return (1);
}
