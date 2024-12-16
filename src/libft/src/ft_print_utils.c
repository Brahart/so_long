/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:27:02 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/12 19:03:42 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ftt_strlen(char	*s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ftt_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ftt_strlen(str));
	return (ftt_strlen(str));
}

int	ft_unnum_len(unsigned long long int n, int baselen)
{
	int	len;

	len = 1;
	while (n >= (unsigned int)baselen)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

int	ft_num_len(long long int n, int baselen)
{
	int	len;

	len = 1;
	if (n < 0)
		n *= -1;
	while (n >= baselen)
	{
		n /= baselen;
		len++;
	}
	return (len);
}
