/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:46:37 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 00:30:33 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_img(t_data *data, t_image img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img.sprite,
		(img.img_width * x), (img.img_height * y));
}
