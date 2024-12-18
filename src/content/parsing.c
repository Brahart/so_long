/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/18 01:03:08 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_extract_map(int fd)
{
	
}

char	**ft_parse_map(int fd, char *data)
{
	int	i;

	i = 0;
	data->map = ft_split(ft_extract_map(fd), '\n');
	// faire une fonction pour verifier qu'il y a bien le nombre de player, exit et collectible needed
	// fonction pour checker si c est un rectangle
	// fonction pour check si il y a bien des murs autour de la map (ligne et colonne)
	//  fonction qui check qu'il n'y ai pas d'autres element que 1, 0, C, E, P
}

char	**ft_verif_map(char **arg, t_data *data)
{
	int	fd;

	fd = 0;
	fd = open(str[1], O_RDONLY);
	if (fd > 0)
		data->map = parse_map(fd, data);
	else
		return(ft_printf("Error\nCan't open file\n"));
	if ((data->content.count_c == 0 || data->content.count_e != 1
		|| data->count_p != 1) && data->map)
	{
		ft_free_map(data);
		return(ft_printf("Error\nNeed 1 Player, 1 Exit and at least 1 Object\n"));
	}
	return(data->map);
}

// char	**extract_map()
// {
// 	int 	fd;
// 	char	*storage;
// 	char	**map;
	
// 	fd = open("map.ber", O_RDONLY);
	
// }

// int main(void)
// {
// 	ft_printf("\e[4;31mSalut %s", "toi");
// 	return(0);
// }

// is the map is surrounded by wall ?

// is the map is rectangular ?

// is the maps line have same lenght ?

// is the file have map ?

// the map must have 1 E and 1 P ?

// the map must have at least 1 C ?

// is the E is available by the P ?

// is the C are whithin reach of P ?
