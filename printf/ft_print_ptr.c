/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:30:11 by autku             #+#    #+#             */
/*   Updated: 2024/05/01 12:51:23 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
