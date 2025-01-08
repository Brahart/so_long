/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 15:40:34 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*extract_map(int fd)
{
	char	*line;
	char	*buffer;

	line = ft_strdup("");
	buffer = ft_strdup("");
	buffer = get_next_line(fd);
	if (fd > 0)
	{
		while (buffer)
		{
			line = ft_strjoin(line, buffer);
			free(buffer);
			buffer = get_next_line(fd);
		}
		return (line);
	}
	ft_error("\e[1;31mERROR\nLecture map has failed");
	return (NULL);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

char	**parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_split(extract_map(fd), '\n');
	check_content(data);
	if (!check_line(data->map[0], data->content.wall))
		return (free_map(data), NULL);
	if (!check_is_rectangle(data->map))
		return (free_map(data), NULL);
	while (data->map[i])
	{
		if (!check_column(data->map[i], data->content.wall, data))
			return (free_map(data), NULL);
		if (!check_content_map(data->map[i], data->content))
			return (free_map(data), NULL);
		i++;
	}
	data->height = i;
	if (!check_line(data->map[i - 1], data->content.wall))
		return (free_map(data), NULL);
	return (data->map);
}

char	**verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (!is_ber(arg[1], ".ber"))
		return (ft_error("\e[1;31mERROR\nMap argument is invalid"), NULL);
	else
	{
		fd = open(arg[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("ERROR\nCan't open file"), NULL);
		if ((data->content.count_c == 0 || data->content.count_ex != 1
				|| data->content.count_p != 1) && data->map)
		{
			free_map(data);
			return (ft_error(
					"\e[1;31mERROR\nNeed 1 Player/Exit and at least 1 Object"),
				NULL);
		}
	}
	close(fd);
	return (data->map);
}
