/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:27 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/11 21:18:31 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > 2147483647 / size)
		return (NULL);
	tab = malloc(size * nmemb);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)tab)[i] = '\0';
		i++;
	}
	return (tab);
}
