/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:31 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/10 17:25:02 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_content(t_data *data)
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
				data->content.count_p += 1;
			if (data->map[i][j] == data->content.exit)
				data->content.count_ex += 1;
			if (data->map[i][j] == data->content.collectible)
				data->content.count_c += 1;
			if (data->map[i][j] == data->content.collectible)
				data->content.count_en += 1;
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_content_map(char *line, t_cont content)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (content.count_p > 1)
			return (ft_error("ERROR\nToo many PLAYER"), 0);
		if (content.count_ex > 1)
			return (ft_error("ERROR\nToo many EXIT"), 0);
		if ((line[i] != content.wall) && (line[i] != content.space)
			&& (line[i] != content.player) && (line[i] != content.exit)
			&& (line[i] != content.collectible) && (line[i] != content.enemy))
		{
			ft_error("ERROR\nThe map contains unknown arguments");
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
	if (line[0] != wall || line[i - 1] != wall)
	{
		ft_error("ERROR\nThe map is invalid\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	check_line(char *line, char wall)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
		{
			ft_error("ERROR\nThe map is invalid");
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

	i = 0;
	j = 0;
	count = 0;
	while (map[0][count])
		count++;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j != count)
			return (ft_error(
					"ERROR\nThe line doesn't have the same length"), 0);
		j = 0;
		i++;
	}
	if (i == j)
		return (ft_error("ERROR\nThe map must be a rectangle"), 0);
	return (1);
}
