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

int	put_ptr(unsigned long long ptr)
{
	int		count;
	char	*digits;

	count = 0;
	digits = "0123456789abcdef";
	if (ptr >= 16)
	{
		count += put_ptr(ptr / 16);
		count += write(1, &digits[ptr % 16], 1);
	}
	else
		count += write(1, &digits[ptr % 16], 1);
	return (count);
}

int	print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	write(1, "0x", 2);
	return (count += put_ptr((unsigned long long)ptr) + 2);
}
