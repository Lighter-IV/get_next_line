/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csangkhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:37:37 by csangkhe          #+#    #+#             */
/*   Updated: 2022/03/17 22:35:45 by csangkhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*get_str(int fd, char *str);
char	*get_line(char *str);
char	*remove_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*find_newline(char *str);
size_t	ft_strlen(char *s);

#endif
