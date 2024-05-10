/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:36:31 by autku             #+#    #+#             */
/*   Updated: 2024/05/10 11:36:49 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*read_line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error opening file\n"),1);
	read_line = get_next_line(fd);
	printf("This is the read line:\n%s\n", read_line);
	close(fd);
	return (0);
}