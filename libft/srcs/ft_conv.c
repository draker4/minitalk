/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:23:01 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:26 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv(va_list ap, const char *str, int i)
{
	if (str[i + 1] && str[i + 1] == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (str[i + 1] && str[i + 1] == 's')
		return (ft_str(va_arg(ap, char *)));
	else if (str[i + 1] && str[i + 1] == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	else if (str[i + 1] && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		return (ft_int(va_arg(ap, int)));
	else if (str[i + 1] && str[i + 1] == 'u')
		return (ft_uint(va_arg(ap, unsigned int)));
	else if (str[i + 1] && str[i + 1] == 'x')
		return (ft_hexa(va_arg(ap, unsigned int), 0));
	else if (str[i + 1] && str[i + 1] == 'X')
		return (ft_hexa(va_arg(ap, unsigned int), 1));
	else if (str[i + 1] && str[i + 1] == '%')
		return (ft_percent());
	return (0);
}
