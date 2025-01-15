/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/15 19:04:55 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_map(t_data *data)
{
	int	i;

	i = 0;
	check_content(data);
	if (!check_line(data->map[0], data->content.wall, data))
		free_map_and_exit(data->map);
	if (!check_is_rectangle(data->map))
		free_map_and_exit(data->map);
	while (data->map[i])
	{
		if (!check_column(data->map[i], data->content.wall, data))
			free_map_and_exit(data->map);
		else if (!check_content_map(data->map[i], data->content))
			free_map_and_exit(data->map);
		i++;
	}
	data->height = i;
	if (!check_line(data->map[i - 1], data->content.wall, data))
		free_map_and_exit(data->map);
}

static char	*extract_map(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp_line;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
		return (free(line), NULL);
	while (buffer)
	{
		tmp_line = ft_strjoin(line, buffer);
		if (!tmp_line)
			return (free(buffer), free(line), NULL);
		free(line);
		line = ft_strdup(tmp_line);
		if (!line)
			return (free(buffer), free(tmp_line), NULL);
		free(buffer);
		free(tmp_line);
		buffer = get_next_line(fd);
	}
	return (line);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

static char	**parse_map(int fd, t_data *data)
{
	char	*str_tmp;

	str_tmp = extract_map(fd);
	if (!str_tmp)
	{
		ft_error("ERROR\nProblem with extract_map function\n");
		return (NULL);
	}
	data->map = ft_split(str_tmp, '\n');
	free(str_tmp);
	if (!data->map)
	{
		ft_error("ERROR\nProblem with split function\n");
		return (NULL);
	}
	check_map(data);
	check_flood_fill(data);
	return (data->map);
}

char	**verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (!is_ber(arg[1], ".ber"))
		return (ft_error("ERROR\nThe argument is not a .ber\n"), NULL);
	fd = open(arg[1], O_RDONLY);
	if (fd > 0)
	{
		data->map = parse_map(fd, data);
		if (!data->map)
			return (ft_error("ERROR\nThe map isn't allocate\n"), NULL);
	}
	else
		return (ft_error("ERROR\nCan't open file\n"), NULL);
	if ((data->content.count_c == 0 || data->content.count_ex != 1
			|| data->content.count_p != 1) && data->map)
	{
		free_map(data->map);
		return (ft_error(
				"ERROR\nNeed 1 Player/Exit and at least 1 Object\n"),
			NULL);
	}
	close(fd);
	return (data->map);
}
