/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:45:49 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/14 18:00:10 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_msg_error(int msg)
{
	if (msg == 0)
		ft_printf("Please enter two arguments!\n");
	else if (msg == 1)
		ft_printf("PID < 0!\n");
	else if (msg == 2)
		ft_printf("Sigemptyset or Sigaddset functions error!\n");
	else if (msg == 3)
		ft_printf("Kill function error!\n");
	else if (msg == 4)
		ft_printf("Malloc function well secured!\n");
	else if (msg == 5)
		ft_printf("Sigaction function error!\n");
	exit(0);
}
