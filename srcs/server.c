/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:56:05 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 19:00:50 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		signal->str = malloc(sizeof(char) * (signal->len + 1));
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
			(signal->str)[signal->nb_char] = '\0';
			signal->nb_char = 0;
			signal->received_string = 1;
		}
	}
}

static void	handler(int sig, siginfo_t	*siginfo, void *context)
{
	static t_signal	signal;

	(void)context;
	(void)siginfo;
	//ft_printf("Process ID sender = %d et sig = %d\n", siginfo->si_pid, sig);
	if (!signal.received_len)
		ft_calcul_len(sig, &signal);
	else
	{
		if (!signal.received_string)
			ft_create_string(sig, &signal);
		if (signal.received_string)
		{
			(signal.str)[signal.len] = '\0';
			ft_printf("%s\n", signal.str);
			signal.received_len = 0;
			signal.received_string = 0;
			signal.len = 0;
			free(signal.str);
			signal.str = NULL;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1 || sigaddset(&sa.sa_mask, SIGUSR1) == -1 \
	|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		return (ft_msg_error(2));
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
	|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_msg_error(5));
	ft_printf("Process ID is : %d\n", getpid());
	while (1)
		pause();
}
