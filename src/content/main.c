/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:45:42 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 01:38:44 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		ft_error("ERROR\nThe number of arguments is invalid", 0);
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		set_content(&data.content);
		data.map = ft_verif_map(av, &data);
		if (data.map)
		{
			set_image(&data);
			init_window(data);
		}
		else
			end_game(&data);
	}
	return(0);
}
