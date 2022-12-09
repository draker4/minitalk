/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:41:19 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:48 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			sum += ft_conv(ap, str, i);
			i += 2;
		}
		else
		{
			ft_putchar(str[i++]);
			sum++;
		}
	}
	va_end(ap);
	return (sum);
}
