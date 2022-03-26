/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:11:49 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/26 15:56:03 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buffer[1024];
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = 1;
	str = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_checknewline(buffer[fd]) && status != 0)
	{
		status = read(fd, str, BUFFER_SIZE);
		if (status == -1)
		{
			free(str);
			return (NULL);
		}
		str[status] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], str);
	}
	free(str);
	str = ft_getstr(buffer[fd]);
	buffer[fd] = ft_remainstr(buffer[fd]);
	return (str);
}
