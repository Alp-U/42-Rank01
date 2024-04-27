/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:29:27 by autku             #+#    #+#             */
/*   Updated: 2024/04/24 22:21:25 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
