/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:55:31 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/19 13:20:38 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map == data->content.player)
				data->content.count_p += 1;
			if (data->map == data->content.exit)
				data->content.count_e += 1;
			if (data->map == data->content.collectible)
				data->content.count_c += 1;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_check_content_map(char *line, t_cont content)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (content.count_p > 1)
			return(ft_error("ERROR\nToo many PLAYER"), 0);
		if (content.count_e > 1)
			return (ft_error("ERROR\nToo many EXIT"), 0);
		if ((line[i] != content.wall) || (line[i] != content.space) 
			|| (line[i] != content.player) || (line[i] != content.exit) 
			|| (line[i] != content.collectible))
			{
				ft_error("ERROR\nThe map contains wrong arguments");
				return (0);
			}
			i++;
	}
	return (1);
}

int	ft_check_column(char *line, char wall)
{
	if (line[0] != wall || line[ft_strlen(line) - 1] != wall)
	{
		ft_error("Error\nThe map is invalid");
		return (0);
	}
	return (1);
}

int	ft_check_line(char *line, char wall)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
		{
			ft_error("Error\nThe map is invalid");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_is_rectangle(char **map)
{
	int			i;
	int			j;
	int			count;
	const char	*er = "Error\nThe line doesn't have the same length";

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
			return (ft_error(er), 0);
		j = 0;
		i++;
	}
	if (i == j)
		return (ft_error("ERROR\nThe map must be a rectangle"), 0);
	return (1);
}
