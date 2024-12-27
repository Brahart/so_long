/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/27 18:00:56 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_extract_map(int fd)
{
	char	*line;
	char	*buffer;

	line = ft_strdup("");
	buffer = ft_strdup("");
	if (fd > 0)
	{
		while (buffer)
		{
			buffer = get_next_line(fd);
			line = ft_strjoin(line, buffer);
			free(buffer);
			buffer = ft_strdup("");
		}
		return(buffer);
	}
	ft_error("ERROR\nLecture map has failed");
	return(NULL);
}


void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_split(ft_extract_map(fd), '\n');
	ft_check_content(data);
	if (!ft_check_line(data->map[0], data->content.wall))
		return (ft_free_map(data), NULL);
	if (!ft_check_is_rectangle(data->map))
		return (ft_free_map(data), NULL);
	while (data->map[i])
	{
		if (!ft_check_column(data->map[i], data->content.wall))
			return (ft_free_map(data), NULL);
		if (!ft_check_content_map(data->map[i], data->content))
			return (ft_free_map(data), NULL);
		i++;
	}
	if (!ft_check_line(data->map[i - 1], data->content.wall))
		return (ft_free_map(data), NULL);
	return (data->map);
	
}

char	**ft_verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
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
	return(data->map);
}
