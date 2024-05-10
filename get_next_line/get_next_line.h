/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:28:53 by autku             #+#    #+#             */
/*   Updated: 2024/05/10 11:26:48 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(char *str);

int		ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);

char	*iterate_buf(int fd);

char	*get_next_line(int fd);

int	main(void);

#endif