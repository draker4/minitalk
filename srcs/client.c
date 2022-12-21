/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:58 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/21 15:59:39 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_global;

static int	ft_send_len(int pid, t_client *client)
{
	if (client->bit_32--)
	{
		if (client->len & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_msg_error(3));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_msg_error(3));
		}
		client->len >>= 1;
	}
	if (!client->bit_32)
		client->len_sent = 1;
	return (1);
}

static int	ft_send_char(t_client *client, int pid)
{
	if (client->bit_8 == 8)
		client->c = ft_reverse_char((client->str)[client->nb_char]);
	if (client->bit_8--)
	{
		if (client->c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_msg_error(3));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_msg_error(3));
		}
		client->c = client->c >> 1;
	}
	if (!client->bit_8)
	{
		client->bit_8 = 8;
		client->nb_char++;
	}
	return (1);
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_global = 1;
	else if (sig == SIGUSR2)
	{
		write(1, "Message received!\n", 18);
		exit(0);
	}
}

static int	ft_check_arg(int *pid, int argc, char **argv)
{
	if (argc != 3)
		return (ft_msg_error(0));
	*pid = ft_atoi(argv[1]);
	if (*pid <= 0)
		return (ft_msg_error(1));
	if ((int)ft_strlen(argv[2]) <= 0)
		return (ft_msg_error(6));
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	t_client			client;

	if (!ft_check_arg(&pid, argc, argv))
		return (0);
	sa.__sigaction_u.__sa_handler = &handler;
	if (!ft_initialize_sa(&sa, 0))
		return (0);
	ft_initialize_client(&client, ft_strlen(argv[2]), argv[2]);
	while (1)
	{
		g_global = 0;
		if (client.len_sent && !ft_send_char(&client, pid) \
		&& client.nb_char < (int)client.len)
			return (0);
		else if (!client.len_sent && !ft_send_len(pid, &client))
			return (0);
		while (!g_global)
			;
	}
}
