/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:25:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/14 18:53:32 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_map(t_data *data)
{
	int	i;

	i = 0;
	check_content(data);
	if (!check_line(data->map[0], data->content.wall, data))
		free_map(data);
	if (!check_is_rectangle(data->map))
		free_map(data);
	while (data->map[i])
	{
		if (!check_column(data->map[i], data->content.wall, data))
			free_map(data);
		if (!check_content_map(data->map[i], data->content))
			free_map(data);
		i++;
	}
	data->height = i;
	if (!check_line(data->map[i - 1], data->content.wall, data))
		free_map(data);
}
