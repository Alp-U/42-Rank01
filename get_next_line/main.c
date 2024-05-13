/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alp <alp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:36:31 by autku             #+#    #+#             */
/*   Updated: 2024/05/13 22:27:57 by alp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	
	/*line = get_next_line(fd);
	printf("%s", line);
	free(line);*/
	
	/*while (read(fd, 0, 0) != EOF)
    {
		line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }*/

	while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	close(fd);
	return (0);
}