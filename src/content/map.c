/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/19 00:00:41 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_extract_map(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp_buffer;
	int		char_read;

	line = ft_strdup("");
	buffer = ft_strdup("");
	if (fd > 0)
	{
		while (buffer)
		{
			buffer = gnl(fd);
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
		free (data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
	return(0);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_split(ft_extract_map(fd), '\n');
	ft_check_content(data);
	if (!ft_check_line(data->map[0], data->content.wall))
		return (ft_free_map(data));
	if (!ft_check_is_rectangle(data->map))
		return (ft_free_map(data));
	while (data->map[i])
	{
		if (!ft_check_column(data->map[i], data->content.wall))
			return (ft_free_map(data));
		if (!ft_check_content_map(data->map[i], data->content)
			return (ft_free_map(data));
		i++;
	}
	if (!ft_check_line(data->map[i - 1], data->content.wall))
		return (ft_free_map(data));
	return (data->map);
	
}

char	**ft_verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	fd = open(arg[1], O_RDONLY);
	if (fd > 0)
		data->map = parse_map(fd, data);
	else
		return(ft_error("ERROR\nCan't open file"));
	if ((data->content.count_c == 0 || data->content.count_e != 1
		|| data->content.count_p != 1) && data->map)
	{
		ft_free_map(data);
		return(ft_error("ERROR\nNeed 1 Player, 1 Exit and at least 1 Object"));
	}
	return(data->map);
}
