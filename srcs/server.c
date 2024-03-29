/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:28:53 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/21 17:15:19 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bit_ok(int client_id, int end, char *str)
{
	int	error;

	error = 0;
	if (!end)
	{
		if (kill(client_id, SIGUSR1) == -1)
			error = 1;
	}
	else
	{
		if (kill(client_id, SIGUSR2) == -1)
			error = 1;
	}
	if (error)
	{
		ft_printf("Kill function error!\n");
		if (str)
			free(str);
		exit (0);
	}
}

static void	ft_calcul_len(int sig, t_signal	*signal)
{
	static int		size;

	if (size < 32)
	{
		if (sig == SIGUSR1)
			signal->len = (signal->len << 1) | 1;
		else
			signal->len = (signal->len << 1);
		size++;
	}
	if (size == 32)
	{
		signal->received_len = 1;
		size = 0;
	}
}

static void	ft_create_string(int sig, t_signal *signal)
{
	if (!signal->str)
		signal->str = malloc((signal->len + 1) * sizeof(char));
	if (!signal->str)
		ft_msg_error(4);
	if (signal->nb_char < (int)signal->len)
	{
		if (sig == SIGUSR1)
			signal->c = (signal->c << 1) | 1;
		else
			signal->c = (signal->c << 1);
		signal->nb_bit_char++;
		if (signal->nb_bit_char == 8)
		{
			signal->nb_bit_char = 0;
			(signal->str)[signal->nb_char] = signal->c;
			signal->c = 0;
			signal->nb_char += 1;
		}
		if (signal->nb_char == (int)signal->len)
		{
			signal->nb_char = 0;
			signal->received_string = 1;
		}
	}
}

static void	handler(int sig, siginfo_t	*siginfo, void *context)
{
	static t_signal	signal;

	(void)context;
	if (siginfo->si_pid != 0)
		signal.client_id = siginfo->si_pid;
	if (signal.received_len && (int)signal.len > 0)
	{
		if (!signal.received_string)
			ft_create_string(sig, &signal);
		if (signal.received_string)
		{
			(signal.str)[signal.len] = '\0';
			ft_printf("%s", signal.str);
			signal.received_len = 0;
			signal.received_string = 0;
			signal.len = 0;
			free(signal.str);
			signal.str = NULL;
			ft_send_bit_ok(signal.client_id, 1, NULL);
		}
	}
	else if (!signal.received_len)
		ft_calcul_len(sig, &signal);
	ft_send_bit_ok(signal.client_id, 0, signal.str);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	if (!ft_initialize_sa(&sa, SA_SIGINFO))
		return (0);
	ft_printf("Process ID is : %d\n", getpid());
	while (1)
		;
}
