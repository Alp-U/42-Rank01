/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autku <autku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:44:15 by autku             #+#    #+#             */
/*   Updated: 2024/05/10 10:26:29 by autku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

// String test #1
/*
int main(void)
{
    int count;

    count = 0;
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the string: %s\n", "World");
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the string: %s\n", "World");
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
	return (0);
}*/
// String test #2
/*
int main(void)
{
    int count;

    count = 0;
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the string: %s\n", NULL);
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the string: %s\n", NULL);
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
	return (0);
}*/

// Digit test
/*
int main(void)
{
    ft_printf("%d\n", ft_printf("%"));
	ft_printf("\n\n");
    printf("%d\n", printf("%"));
    return (0);
}*/

// Pointer test #1
/*
int main(void)
{
    int count;
    char *ptr;

    ptr = NULL;
    count = 0;
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the pointer: %p\n", ptr);
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the pointer: %p\n", ptr);
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
	return (0);
}*/

// Pointer test #2
/*
int main(void)
{
    int count;
    char *ptr;

    ptr = malloc(10);
    count = 0;
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the pointer: %p\n", ptr);
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the pointer: %p\n", ptr);
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
    free(ptr);
	return (0);
}*/

// Hex test #2
/*
int main(void)
{
    int count;
    int hex;

    hex = 270324;
    count = 0;
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the hex number: %u\n", hex);
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the hex number: %u\n", hex);
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
	return (0);
}*/
/*
int main(void)
{
    int count;

    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\n");
    ft_printf("\nMy func:\n");
	count = ft_printf("This is the digit: %u\n", 1000);
    ft_printf("The chars written are %d\n", count);

	ft_printf("\n\nThe og func:\n");
    count = printf("This is the digit: %u\n", 1000);
    printf("The chars written are %d\n", count);
    ft_printf("\n/+++++++++++++++++++++++++++++++++++++++/\n\nlooks like it's working\n\n");
	return (0);
}*/
/*
int main(void)
{
    int d;
    int count;

    d = printf("%")
    d = (printf("%"));
    printf("%d\n", d);

    d = (ft_printf("%"));
    ft_printf("%d", d);
	return (0);
}*/