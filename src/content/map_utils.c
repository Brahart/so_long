/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:25:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 21:53:58 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map_and_exit(char **map)
{
	free_map(map);
	exit(0);
}

void	free_flood(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	copy_map(t_data *data)
{
	int	i;

	i = 0;
	data->flood = ft_calloc(data->height + 1, sizeof(char *));
	if (!data->flood)
	{
		ft_error("ERROR with allocation of temporary map for floodfill\n");
		return (0);
	}
	while (data->map[i])
	{
		data->flood[i] = ft_strdup(data->map[i]);
		if (!data->flood[i])
		{
			free_flood(data->flood, i);
			ft_error("ERROR with map dupliaction for floodfill\n");
			return (0);
		}
		i++;
	}
	return (i);
}

void	check_flood_fill(t_data *data)
{
	data->content.tmp_c = data->content.count_c;
	data->content.tmp_ex = 1;
	if (!copy_map(data))
	{
		ft_error("ERROR\ncopy_map has failed");
		free_map(data->map);
		exit (0);
	}
	flood_fill(data, data->pos.x, data->pos.y);
	free_map(data->flood);
	if (data->content.tmp_c)
	{
		ft_error("ERROR\nAll collectible are not accessible");
		free_map(data->map);
		exit(0);
	}
	if (data->content.tmp_ex)
	{
		ft_error("ERROR\nThe exit is not accessible");
		free_map(data->map);
		exit(0);
	}
}

int	verif_double_backspace(char *line)
{
	int	i;

	i = 1;
	if (line[0] == '\n')
	{
		ft_error("ERROR\nThe map contains invalid return to line\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
			{
				ft_error(
					"ERROR\nThe map contains invalid return to line\n");
				return (0);
			}
		}
		i++;
	}
	if (line[i - 1] == '\n')
		return (ft_error(
				"ERROR\nThe map contains invalid return to line\n"), 0);
	return (1);
}
