/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:45:42 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/19 21:10:38 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int main(int ac, char **av)
{
	t_data	*data;
	
	data = NULL;
	if (ac != 2)
		ft_error("Error\nThe number of arguments is invalid");
	set_content(&data->content);
	data->map = ft_verif_map(av, data);
	return(0);
}
