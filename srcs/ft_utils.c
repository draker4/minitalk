/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:07:30 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 18:41:42 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_reverse_len(size_t len)
{
	int		bits;
	size_t	reverse;

	bits = 32;
	reverse = 0;
	while (bits--)
	{
		reverse = (reverse << 1) | (len & 1);
		len >>= 1;
	}
	return (reverse);
}

unsigned char	ft_reverse_char(unsigned char c)
{
	int				bits;
	unsigned char	reverse;

	bits = 8;
	reverse = 0;
	while (bits--)
	{
		reverse = (reverse << 1) | (c & 1);
		c >>= 1;
	}
	return (reverse);
}
