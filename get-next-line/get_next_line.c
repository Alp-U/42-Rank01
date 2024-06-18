/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:13:28 by alp               #+#    #+#             */
/*   Updated: 2024/06/17 16:46:06 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	join_to_stash(char **stash, char *buf)
{
	char	*temp;

	temp = *stash;
	*stash = ft_strjoin(temp, buf);
	if (!*stash)
		free(*stash);
	free(temp);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char	*get_line(char *line_buf)
{
	char	*stash;
	int		i;

	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
		i++;
	if (!line_buf[i])
		return (NULL);
	stash = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line_buf[i + 1] = '\0';
	return (stash);
}

char	*iterate_buf(int fd, char *buf, char *stash)
{
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), free(buf), stash = NULL, NULL);
		else if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (stash)
			join_to_stash(&stash, buf);
		else
		{
			stash = ft_strdup(buf);
			if (!stash)
				return (free(stash), free(buf), stash = NULL, NULL);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*final_str;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(stash), stash = NULL, NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(buf), free(stash), stash = NULL, NULL);
	final_str = iterate_buf(fd, buf, stash);
	if (!final_str)
		return (NULL);
	stash = get_line(final_str);
	return (final_str);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);	

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
