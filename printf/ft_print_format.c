/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:30:42 by autku             #+#    #+#             */
/*   Updated: 2024/05/09 20:11:05 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += print_udigit((long)(va_arg(ap, int)),10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (specifier == 'X')
		count += print_hexc((long)(va_arg(ap, unsigned int)), 16);
	else
		count += print_char(specifier);
	return (count);
}
