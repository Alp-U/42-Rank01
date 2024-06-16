/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:28:53 by autku             #+#    #+#             */
/*   Updated: 2024/06/15 15:22:55 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	join_to_stash(char **stash, char *buf);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *str);

char	*ft_strdup(char *str);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_lines(char *str);

char	*iterate_buf(int fd, char *buf, char *stash);

char	*get_next_line(int fd);

#endif
