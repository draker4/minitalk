/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:31:12 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 15:57:27 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putnbr_base(unsigned long long nb, int *count, int maj)
{
	if (nb >= 16)
		ft_putnbr_base(nb / 16, count, maj);
	*count += 1;
	if (!maj)
		ft_putchar("0123456789abcdef"[nb % 16]);
	else
		ft_putchar("0123456789ABCDEF"[nb % 16]);
}
