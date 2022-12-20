/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:07:30 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/15 14:27:22 by bperriol         ###   ########lyon.fr   */
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

int	ft_initialize_sa(struct sigaction *sa, int flag)
{
	if (sigemptyset(&sa->sa_mask) == -1 \
	|| sigaddset(&sa->sa_mask, SIGUSR1) == -1 \
	|| sigaddset(&sa->sa_mask, SIGUSR2) == -1)
		return (ft_msg_error(2));
	sa->sa_flags = flag;
	if (sigaction(SIGUSR1, sa, NULL) == -1 \
	|| sigaction(SIGUSR2, sa, NULL) == -1)
		return (ft_msg_error(5));
	return (1);
}

void	ft_initialize_client(t_client *client, size_t len, char *str)
{
	client->str = str;
	client->len = ft_reverse_len(len);
	client->bit_32 = 32;
	client->bit_8 = 8;
	client->len_sent = 0;
	client->c = 0;
	client->nb_char = 0;
}
