/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:58 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 18:46:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_send_len(size_t len, int pid)
{
	size_t	reverse;
	int		bits;

	bits = 32;
	reverse = ft_reverse_len(len);
	while (bits--)
	{
		if (reverse & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_msg_error(3));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_msg_error(3));
		}
		reverse >>= 1;
		usleep(100);
	}
	return (1);
}

static int	ft_send_char(unsigned char c, int pid)
{
	int				bits;
	unsigned char	reverse;

	bits = 0;
	reverse = ft_reverse_char(c);
	while (bits < 8)
	{
		if (reverse & 1)
		{
			//ft_printf("1\n");
			if (kill(pid, SIGUSR1) == -1)
				return (ft_msg_error(3));
		}
		else
		{
			//ft_printf("0\n");
			if (kill(pid, SIGUSR2) == -1)
				return (ft_msg_error(3));
		}
		reverse = reverse >> 1;
		bits++;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;

	if (argc != 3)
		return (ft_msg_error(0));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_msg_error(1));
	i = 0;
	if (!ft_send_len(ft_strlen(argv[2]), pid))
		return (0);
	while (argv[2][i])
	{
		if (!ft_send_char(argv[2][i++], pid))
			return (0);
	}
}
