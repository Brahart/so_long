/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:45:42 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/17 11:28:03 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("ERROR\nThe number of arguments is invalid"), 0);
	data.count = 0;
	set_content(&data.content);
	data.map = verif_map(av, &data);
	if (!data.map)
	{
		free(data.map);
		return (ft_error("ERROR with map allocation\n"), 0);
	}
	if (data.map)
	{
		set_assets(&data);
		init_window(&data);
		free(data.map);
	}
	else
		end_game(&data);
}
