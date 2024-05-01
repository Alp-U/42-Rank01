/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:44:32 by autku             #+#    #+#             */
/*   Updated: 2024/05/01 15:46:23 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_digit(long n, int base)
{
	int		count;
	char	*hexd;

	hexd = "0123456789abcdef";
	if (n < base)
		return (print_char(hexd[n]));
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	count = print_digit(n / base, base);
	return (count + print_digit(n % base, base));
}

int	print_hexc(long n, int base)
{
	int		count;
	char	*hexd;

	hexd = "0123456789ABCDEF";
	if (n < base)
		return (print_char(hexd[n]));
	count = print_hexc(n / base, base);
	return (count + print_hexc(n % base, base));
}

int	print_ptr(long n, int base)
{
	int		count;
	char	*hexd;

	hexd = "0123456789abcdef";
	if (n < base)
		return (print_char(hexd[n]));
	count = print_ptr(n / base, base);
	return (count + print_ptr(n % base, base));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'u' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'p')
	{
		if (va_arg(ap, void *) == NULL)
		{
			count += write(1, "(nil)", 5);
			return (count);
		}
		write(1, "0x", 2);
		count += print_ptr((long)(va_arg(ap, void *)), 16) + 2;
	}
	else if (specifier == 'X')
		count += print_hexc((long)(va_arg(ap, unsigned int)), 16);
	else
		count += print_char(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == '\0' || (*(format + 1) != 'c' && *(format + 1) != 's' && *(format + 1) != 'p' && *(format + 1) != 'd' && *(format + 1) != 'i' && *(format + 1) != 'u' && *(format + 1) != 'x' && *(format + 1) != 'X' && *(format + 1) != '%')))
		{
			count = -1;
			break;
		}
		else if (*format == '%')
		{
            if (*(format + 1) == '%')
				count += print_format(*(format + 1), ap);
            else
                return (-1);
        }
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}