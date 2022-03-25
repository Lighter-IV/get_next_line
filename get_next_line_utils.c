/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:57:17 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/25 22:19:25 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	ft_checknewline(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (*str == '\n')
			return (true);
		str++;
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
	char	*strjoin;
	size_t	index;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	index = -1;
	strjoin = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (strjoin == NULL)
		return (NULL);
	while (s1[++index])
		strjoin[index] = s1[index];
	while (*s2)
	{
		strjoin[index++] = *s2;
		s2++;
	}
	strjoin[index] = '\0';
	free(s1);
	return (strjoin);
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
	char	*strline;
	int		index;

	index = 0;
	if (!str[0])
		return (NULL);
	while (str[index] && (str[index] != '\n'))
		index++;
	if (str[index] == '\n')
		index++;
	strline = (char *) malloc(sizeof(char) * (index + 1));
	if (!strline)
		return (NULL);
	index = 0;
	while (str[index] && (str[index] != '\n'))
	{
		strline[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		strline[index++] = '\n';
	strline[index] = '\0';
	return (strline);
}
