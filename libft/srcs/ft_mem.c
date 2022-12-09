/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:39:53 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/03 11:02:21 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		i++;
	}
	if (*((unsigned char *)s) == (unsigned char)c && i < n)
		return ((void *)s);
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (*p1 == *p2 && i < n - 1)
	{
		p1++;
		p2++;
		i++;
	}
	if (p1 != p2 && i < n)
		return (*p1 - *p2);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL && n)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((!dst && !src) || (!dst && !src && len))
		return (NULL);
	if (dst > src)
	{
		while (len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*copy;

	copy = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		copy[i++] = (unsigned char) c;
	}
	b = copy;
	return (b);
}
