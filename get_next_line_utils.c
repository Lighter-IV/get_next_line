/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:57:17 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/17 22:42:39 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		index;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	index = 0;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	free(s1);
	while (*s2 != '\0')
	{
		str[index] = *s2;
		index++;
		s2++;
	}
	str[index] = '\0';
	return (str);
}

char	*remove_line(char *str)
{
	char	*remove;
	int		n_str;
	int		n_remove;

	n_str = 0;
	n_remove = 0;
	while (str[n_str] && (str[n_str] != '\n'))
		n_str++;
	if (!str[n_str])
	{
		free(str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str) - n_str));
	if (!str)
		return (NULL);
	n_str++;
	while (str[n_str])
		remove[n_remove++] = str[n_str++];
	remove[n_remove] = '\0';
	free(str);
	return (remove);
}

char	*get_line(char *str)
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
	line = (char *) malloc(sizeof(char) * ++index);
	if (!line)
		return (NULL);
	index = 0;
	while (str[index] && (str[index] != '\n'))
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		str[index++] = '\n';
	str[index] = '\0';
	return (line);
}

char	*get_str(int fd, char *str)
{
	char	*temp;
	int		index;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	index = 1;
	while (!fine_newline(str) && index != 0)
	{
		index = read(fd, str, BUFFER_SIZE);
		if (index == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[index] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}
