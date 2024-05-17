# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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

char	*ft_strjoin(char const *s1, char const *s2)
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
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  i;

        i = 0;
        if (size > 0)
        {
                while (src[i] && i < (size - 1))
                {
                        dst[i] = src[i];
                        i++;
                }
                dst[i] = 0;
        }
        while (src[i])
                i++;
        return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *str;
        size_t  slen;
        size_t  fin;

        if (!s)
                return (0);
        slen = ft_strlen(s);
        if (start >= slen)
                return (ft_strdup(""));
        fin = 0;
        if (start < slen)
                fin = slen - start;
        if (fin > len)
                fin = len;
        str = (char *)malloc(sizeof(char) * (fin + 1));
        if (!str)
                return (0);
        ft_strlcpy(str, s + start, fin + 1);
        return (str);
}

/*******************************************************************************************************/
/*******************************************************************************************************/
/*******************************************************************************************************/
/*******************************************************************************************************/

char	*get_line(char *stash)
{
	int		i;
	char	*new_str;

	i = 0;
	while (!stash[i] || stash[i] != '\n')
		i++;
	new_str = ft_substr(stash, 0, i);
	new_str[i] = '\0';
	return (new_str);
}

char	*iterate_buf(int fd, char *buf, char *stash)
{
	int	bytes;
	char *temp;

	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = '\0';
        if (stash)
        {
            temp = stash;
            stash = ft_strjoin(temp, buf);
            free(temp);
        }
        else
        {
            stash = ft_strdup(buf);
        }
		if (ft_strchr(stash, '\n'))
			break;
    }
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*final_str;
	char		*buf;
	
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	stash = iterate_buf(fd, buf, stash);
	final_str = get_line(stash);
	free(stash);
	return (final_str);
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}
/*
int main(void)
{
    int 	fd;
    char 	*line;
	int		i;

	i = 0;
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return 1;

    while (i < 3)
    {
		line = get_next_line(fd);
        printf("%s", line);
		i++;
		free(line);
    }
    close(fd);
    return 0;
}*/