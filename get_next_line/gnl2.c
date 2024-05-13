/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alp <alp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:15:17 by autku             #+#    #+#             */
/*   Updated: 2024/05/11 17:32:33 by alp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*iterate_buf(int fd, char stash, char *buf)
{
	int		b_read;
	char	*line;
	char	*buf;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (b_read == 0)
			break;
		buffer[b_read] = 0;
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash

	line = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = iterate_buf(fd, stash ,buf);
	return (line);
}
int	main(void)
{
	int		fd;
	char	*read_line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error opening file\n"), 1);
	read_line = get_next_line(fd);
	printf("This is the read line:\n%s\n\n", read_line);
	close(fd);
	return (0);
}