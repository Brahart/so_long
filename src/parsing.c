/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:31:13 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/12 15:51:55 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_verif_map(int fd)
{
	char	**map;
	char	*tmp2;
	char	*tmp1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(tmp1 = get_next_line(fd))
		tmp1 = ft_strjoin(tmp2, tmp1);
	map = ft_split(tmp1, "\n");
	while(map[i][j])
	{
		if(map[0][j] == 0);
			return(ft_printf("Invalid map"), NULL);
		if(map[ft_strlen(*map[i])][j] == 0)
			return(ft_printf("Invalid map"), NULL);
		if(map[i][0] == 0)
			return(ft_printf("Invalid map"), NULL);
		if(map[0][ft_strlen(map[i][j])] == 0);
			return(ft_printf("Invalid map"), NULL);
	}
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
