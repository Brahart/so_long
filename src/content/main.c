/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:45:42 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 23:10:16 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("ERROR\nThe number of arguments is invalid"), 0);
	data.count = 0;
	set_content(&data);
	data.map = verif_map(av, &data);
	if (!data.map)
	{
		free(data.map);
		return (ft_error("ERROR with map allocation\n"), 0);
	}
	init_mlx_ptr(&data);
	if (!data.mlx_ptr)
		free_map_and_exit(data.map);
	if (data.map)
	{
		set_assets(&data);
		init_window(&data);
		free(data.map);
	}
	else
		end_game(&data);
}
