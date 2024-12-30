/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 01:43:02 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*extract_map(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp_buffer;

	line = ft_strdup("");
	buffer = ft_strdup("");
	tmp_buffer = buffer;
	if (fd > 0)
	{
		while (buffer)
		{
			buffer = get_next_line(fd);
			line = ft_strjoin(line, buffer);
			free(buffer);
		}
		return(line);
	}
	ft_error("ERROR\nLecture map has failed");
	return(NULL);
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
	//i = 1
	data->map = ft_split(ft_extract_map(fd), '\n');
	ft_check_content(data);
	if (!ft_check_line(data->map[0], data->content.wall))
		return (ft_free_map(data), NULL);
	if (!ft_check_is_rectangle(data->map))
		return (ft_free_map(data), NULL);
	while (data->map[i])
	{
		if (!ft_check_column(data->map[i], data->content.wall, data))
			return (ft_free_map(data), NULL);
		if (!ft_check_content_map(data->map[i], &data->content))
			return (ft_free_map(data), NULL);
		i++;
	}
	data->height = i;
	if (!ft_check_line(data->map[i - 1], data->content.wall))
		return (ft_free_map(data), NULL);
	return (data->map);
}

char	**verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (!ft_strchr(arg[1], ".ber"))
		return (ft_error("ERROR\nMap argument is invalid"));
	else
	{
		fd = open(arg[1], O_RDONLY);
		if (fd > 0)
			data->map = ft_parse_map(fd, data);
		else
			return(ft_error("ERROR\nCan't open file"), NULL);
		if ((data->content.count_c == 0 || data->content.count_e != 1
			|| data->content.count_p != 1) && data->map)
		{
			ft_free_map(data);
			return(ft_error("ERROR\nNeed 1 Player, 1 Exit and at least 1 Object"), NULL);
		}
	}
	return(data->map);
}
