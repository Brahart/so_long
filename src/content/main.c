/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:45:42 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/06 17:25:42 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("\e[1;31mERROR\nThe number of arguments is invalid");
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		set_content(&data.content);
		data.map = verif_map(av, &data);
		if (data.map)
		{
			set_assets(&data);
			init_window(&data);
		}
		else
			end_game(&data);
	}
	return (0);
}
