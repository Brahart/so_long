/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/13 19:22:39 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


char	*extract_map(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp_line;

	line = ft_strdup("");
	if (fd > 0)
	{
		buffer = get_next_line(fd);
		while (buffer)
		{
			tmp_line = ft_strjoin(line, buffer);
			free(line);
			line = ft_strdup(tmp_line);
			free(buffer);
			free(tmp_line);
			buffer = get_next_line(fd);
		}
		return (line);
	}
	ft_error("ERROR\nLecture map has failed");
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
	int		i;
	char	*str_tmp;

	str_tmp = extract_map(fd);
	i = 0;
	data->map = ft_split(str_tmp, '\n');
	free(str_tmp);
	check_content(data);
	if (!check_line(data->map[0], data->content.wall, data))
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
	if (!check_line(data->map[i - 1], data->content.wall, data))
		return (free_map(data), NULL);
	return (data->map);
}

char	**verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (!is_ber(arg[1], ".ber"))
		return (ft_error("ERROR\nMap argument is invalid"), NULL);
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
					"ERROR\nNeed 1 Player/Exit and at least 1 Object"),
				NULL);
		}
	}
	close(fd);
	return (data->map);
}
