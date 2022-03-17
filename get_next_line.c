/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:22:59 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/17 22:52:13 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line_str;
	static char	*all_str;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all_str = get_str(fd, all_str);
	if (!all_str)
		return (NULL);
	line_str = get_line(all_str);
	all_str = remove_line(all_str);
	return (line_str);
}
