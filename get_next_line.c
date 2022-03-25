/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:22:59 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/25 17:52:46 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buffer;
	int			status;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	status = 1;
	while (!ft_checknewline(buffer) && status != 0)
	{
		status = read(fd, str, BUFFER_SIZE);
		if (status == -1)
		{
			free(str);
			return (NULL);
		}
		str[status] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	str = ft_getstr(buffer);
	buffer = ft_remainstr(buffer);
	return (str);
}
