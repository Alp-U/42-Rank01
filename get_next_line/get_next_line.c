/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:15:17 by autku             #+#    #+#             */
/*   Updated: 2024/05/10 12:19:49 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *buffer)
{
	int		i;
	int		count;
	char	*final_buf;

	i = 0;
	count = 0;
	while (*buffer != '\n' || !buffer)
	{
		count++;
		buffer++;
	}
	final_buf = (char *)malloc(sizeof(char) * count + 1);
	if (!final_buf)
		return (final_buf);
	while (i <= count)
	{
		final_buf[i] = buffer[i];
		i++;
	}
	final_buf[i] = '\0';
	return (final_buf);
}

char	*iterate_buf(int fd)
{
	static int	line;
	char		*buf;

	line = 1;
	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	line = read(fd, buf, BUFFER_SIZE);
	if (line == 0)
		return (NULL);
	if (ft_strchr(buf, '\n') == 1)
		return (buf);
	else
	{
		free(buf);
		iterate_buf(fd);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buffer = iterate_buf(fd);
	if (!buffer)
		return (NULL);
	return (set_line(buffer));
}
