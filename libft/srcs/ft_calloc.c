/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:03:28 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/14 10:40:35 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;

	if (count * size == 0)
	{
		p = malloc(0);
		return (p);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	while (i < count * size)
		((unsigned char *)p)[i++] = 0;
	return (p);
}
