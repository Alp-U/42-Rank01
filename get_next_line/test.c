/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alp <alp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:15:17 by autku             #+#    #+#             */
/*   Updated: 2024/05/11 16:59:11 by alp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dupstr;
	int		i;

	i = 0;
    if (!str)
	{
        return (NULL);
	}
	dupstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dupstr)
		return (NULL);
	while (str[i])
	{
		dupstr[i] = str[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
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

char	*ft_strjoin(const char *s1,const char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}


//Utils above

char	*iterate_buf(int fd, char *stash, char *buf)
{
	int		b_read;
    char    *temp;

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
		buf[b_read] = '\0';
        temp = stash;
		stash = ft_strjoin(temp, buf);
        free(temp);
        temp = NULL;
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

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
		return (printf("Error opening file\n"),1);
	read_line = get_next_line(fd);
	printf("This is the read line:\n%s\n\n", read_line);
	close(fd);
    free(read_line);
	return (0);
}