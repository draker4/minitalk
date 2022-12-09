/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:54:30 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 17:07:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c % 256)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = &((char *)s)[i];
		i++;
	}
	if (!(char)c)
		p = &((char *)s)[i];
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
		str[i++] = ((char *)s2)[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			size;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else
		size = ft_strlen(s + start);
	if (size > len)
		size = len;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
