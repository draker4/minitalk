/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:42:31 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_initialize(char *s, int j)
{
	int	i;

	i = 0;
	if (s[j] == '\0')
		s[i] = '\0';
	else
	{
		while (s[j])
			s[i++] = s[j++];
		s[i] = '\0';
	}
}

char	*ft_cat_char(char *str, char c)
{
	char	*copy;
	int		i;

	i = -1;
	if (!str)
	{
		copy = malloc(sizeof(char) * (2 + ++i));
		if (!copy)
			return (NULL);
	}
	else
	{
		copy = malloc(sizeof(char) * ((int)ft_strlen(str) + 2));
		if (!copy)
		{
			free(str);
			return (NULL);
		}
		while (str[++i])
			copy[i] = str[i];
		free(str);
	}
	copy[i] = c;
	copy[++i] = '\0';
	return (copy);
}

int	ft_is_newline(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
