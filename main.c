/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:44:15 by autku             #+#    #+#             */
/*   Updated: 2024/04/24 22:17:59 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
    int count;

    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
    count = ft_printf("This is the string: %s\n", "World");
    ft_printf("The chars written are %d\n", count);
    ft_printf("\nThe og func:\n");
    count = printf("This is the string: %s\n", "World");
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
    return (0);
}