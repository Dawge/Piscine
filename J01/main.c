/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <rostroh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:48 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 16:31:19 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>

int			main(int argc, char **argv)
{
	int		i;
	size_t	t;
	wchar_t c;

	i = 42;
	t = 8;
	c = L'芝';
//	ft_printf("%s", NULL);
//	printf("%s", NULL);
//	printf("%c", c);
//	ft_printf("%c", c);
//	ft_printf("%-+10.5d\n", 4242);
//	printf("%-+10.5d", 4242);
	//	ft_printf("%5.s\n", "abcdefghijkl");
//	printf("%5.s\n", "abcdefghijkl");
	//	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
//	printf("@moulitest: %5.x %5.0x\n", 0, 0);
	//	ft_printf("%d\n", -1);
//	printf("%d\n", -1);
//	ft_printf("%d\n", -1);
//	printf("%d\n", -1);
//	ft_printf("%lu", -42);
//	ft_printf("%ld\n", 9223372036854775807);
//	printf("%ld\n", 9223372036854775807);
//	ft_printf("%5.o\n", 0);
//	printf("%5.o\n", 0);
//	ft_printf("%10s is a string\n", "");
//	printf("%10s is a string\n", "");
//	ft_printf("%2c\n", 0);
//	printf("%2c\n", 0);
//	ft_printf("%2.2s\n", "");
//	printf("%2.2s\n", "");
//	ft_printf("%.2s %s %s %.3s\n", "This", "is", "a", "string");
//	printf("%.2s %s %s %.3s\n", "This", "is", "a", "string");
	ft_printf("%jx\n", -4294967296);
	printf("%jx\n", -4294967296);
	return (0);
}
