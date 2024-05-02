/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:46:40 by autku             #+#    #+#             */
/*   Updated: 2024/05/01 15:39:28 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == '\0' || (*(format + 1) != 'c'
					&& *(format + 1) != 's' && *(format + 1) != 'p'
					&& *(format + 1) != 'd' && *(format + 1) != 'i'
					&& *(format + 1) != 'u' && *(format + 1) != 'x'
					&& *(format + 1) != 'X' && *(format + 1) != '%')))
			return (write(1, "-1", 2), -1);
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int	count;

	ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
	ft_printf("\nMy func:\n");
	count = ft_printf("This is the string: %s\n", "World");
	ft_printf("The chars written are %d\n", count);
	ft_printf("\nThe og func:\n");
	count = printf("This is the string: %s\n", "World");
	printf("The chars written are %d\n", count);
	ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n
	looks like it's working\n\n");
	return (0);
}*/
