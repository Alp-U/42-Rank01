# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

// Utility functions
size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}

int ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return 1;
        s++;
    }
    return 0;
}

char *ft_strdup(const char *s1)
{
    size_t len = ft_strlen(s1) + 1;
    char *copy = (char *)malloc(len);
    if (copy)
        strcpy(copy, s1);
    return copy;
}

char *ft_strjoin(const char *s1, const char *s2)
{
    if (!s1 || !s2)
        return NULL;

    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *result = (char *)malloc(len1 + len2 + 1);

    if (!result)
        return NULL;

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *get_lines(char *str)
{
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if (str[i] == '\n')
        i++;

    char *new_str = (char *)malloc(i + 1);
    if (!new_str)
        return NULL;

    strncpy(new_str, str, i);
    new_str[i] = '\0';
    return new_str;
}

char *iterate_buf(int fd, char *buf, char *stash)
{
    int bytes;
    char *temp;

    while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = '\0';
        temp = stash;
        stash = ft_strjoin(temp, buf);
        free(temp);
        if (ft_strchr(buf, '\n'))
            break;
    }
    return stash;
}

char *get_next_line(int fd)
{
    static char *stash;
    char *buf;
    char *line;
    char *temp;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return NULL;

    stash = iterate_buf(fd, buf, stash);
    free(buf);
    if (!stash)
        return NULL;

    line = get_lines(stash);

    int line_len = ft_strlen(line);
    if (ft_strlen(stash) == line_len)
    {
        free(stash);
        stash = NULL;
    }
    else
    {
        temp = stash;
        stash = ft_strdup(stash + line_len);
        free(temp);
    }

    return line;
}

int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
