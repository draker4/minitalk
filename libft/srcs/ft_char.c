/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:09:17 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:29 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_hexa(unsigned int nb, int maj)
{
	int	count;

	count = 0;
	ft_putnbr_base(nb, &count, maj);
	return (count);
}

int	ft_int(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	ft_uint(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_itoa_unsigned(nb);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	ft_str(char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	ft_putstr(s);
	return (ft_strlen(s));
}
