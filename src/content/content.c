/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:09 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/19 21:07:48 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_content(t_cont *content)
{
	content->wall = '1';
	content->space = '1';
	content->player = 'P';
	content->exit = 'E';
	content->collectible = 'C';
	content->count_e = 0;
	content->count_p = 0;
	content->count_c = 0;
}
