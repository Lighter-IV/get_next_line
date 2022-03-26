/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:14:39 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/26 15:12:56 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	index;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	strjoin = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	index = -1;
	while (s1[++index])
		strjoin[index] = s1[index];
	while (*s2)
	{
		strjoin[index++] = *s2;
		s2++;
	}
	free(s1);
	strjoin[index] = '\0';
	return (strjoin);
}

char	*ft_getstr(char *str)
{
	char	*strline;
	int		index;

	if (!str[0])
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
		index++;
	if (str[index] == '\n')
		index++;
	strline = (char *) malloc(sizeof(char) * (index + 1));
	if (!strline)
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
	{
		strline[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		strline[index++] = '\n';
	strline[index] = '\0';
	return (strline);
}

char	*ft_remainstr(char *str)
{
	char	*remain;
	int		n_str;
	int		n_remain;

	n_str = 0;
	while (str[n_str] != '\n' && str[n_str])
		n_str++;
	if (!str[n_str])
	{
		free(str);
		return (NULL);
	}
	remain = (char *) malloc(sizeof(char) * (ft_strlen(str) - n_str + 1));
	if (!remain)
		return (NULL);
	n_remain = 0;
	n_str++;
	while (str[n_str])
		remain[n_remain++] = str[n_str++];
	remain[n_remain] = '\0';
	free(str);
	return (remain);
}
