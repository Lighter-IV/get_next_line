/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:57:17 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/25 17:54:57 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	ft_checknewline(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (false);
	while (str[index])
	{
		if (str[index] == '\n')
			return (true);
		index++;
	}
	return (false);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	index;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	index = -1;
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++index])
			str[index] = s1[index];
	while (*s2)
	{
		str[index++] = *s2;
		s2++;
	}
	str[index] = '\0';
	free(s1);
	return (str);
}

char	*ft_remainstr(char *str)
{
	char	*remain;
	int		n_str;
	int		n_remain;

	n_str = 0;
	n_remain = 0;
	while (str[n_str] && (str[n_str] != '\n'))
		n_str++;
	if (!str[n_str])
	{
		free(str);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (ft_strlen(str) - n_str + 1));
	if (!remain)
		return (NULL);
	n_str++;
	while (str[n_str])
		remain[n_remain++] = str[n_str++];
	remain[n_remain] = '\0';
	free(str);
	return (remain);
}

char	*ft_getstr(char *str)
{
	char	*line;
	int		index;

	index = 0;
	if (!str[0])
		return (NULL);
	while (str[index] && (str[index] != '\n'))
		index++;
	if (str[index] == '\n')
		index++;
	line = (char *) malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (str[index] && (str[index] != '\n'))
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}
