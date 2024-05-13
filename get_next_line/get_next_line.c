/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alp <alp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:13:28 by alp               #+#    #+#             */
/*   Updated: 2024/05/13 22:40:21 by alp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_lines(char *str)
{
	static int		i;
	char			*new_str;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i] || !str[1])
        return (NULL);
    new_str = ft_substr(str, i + 1, ft_strlen(str) - i);
    if (!new_str)
    {
        free(new_str);
        new_str = NULL;
    }
	free(str);
    return (new_str);
}

char	*iterate_buf(int fd, char *buf, char *stash)
{
	int		bytes;
	char	*temp;
	
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break;
		if (!stash)
			stash = ft_strdup("");
		buf[bytes] = 0;
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n') == 1)
			break;
	}
	return (free(buf), buf = NULL, stash);
}

char	*get_next_line(int  fd)
{
	char		*buf;
	char		*final_str;
	static char	*stash;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == 0)
	{
		free(stash);
		free(buf);
		stash = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	final_str = iterate_buf(fd, buf, stash);
	stash = get_lines(final_str);
	return (final_str);
}