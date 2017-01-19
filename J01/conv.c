/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:16:13 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 15:00:49 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*gestion_arg(int arg, int base, char letter, va_list ap)
{
	if (arg == 2)
		return (get_base(va_arg(ap, long), base, letter));
	if (arg == 3)
		return (get_base(va_arg(ap, long long), base, letter));
	if (arg == 4)
		return (get_base((short)va_arg(ap, int), base, letter));
	if (arg == 5)
		return (get_base((char)va_arg(ap, int), base, letter));
	if (arg == 6)
		return (get_base(va_arg(ap, intmax_t), base, letter));
	if (arg == 8)
		return (get_base(va_arg(ap, size_t), base, letter));
	return (NULL);
}

char	*gestion_arg2(int arg, int base, char letter, va_list ap)
{
	if (arg == 2)
		return (unsigned_get_base(va_arg(ap, unsigned long), base, letter));
	if (arg == 3)
		return (unsigned_get_base(va_arg(ap, unsigned long long), base, letter));
	if (arg == 4)
		return (unsigned_get_base(va_arg(ap, unsigned int), base, letter));
	if (arg == 5)
		return (unsigned_get_base(va_arg(ap, unsigned int), base, letter));
	if (arg == 6)
		return (unsigned_get_base(va_arg(ap, unsigned long), base, letter));
	if (arg == 8)
		return (unsigned_get_base(va_arg(ap, size_t), base, letter));
	return (NULL);
}

char	*poney3(t_arg param, va_list ap)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (param.letter == 'c')
	{
		str[0] = va_arg(ap, int);
		str[1] = '\0';
		return (str);
	}
	if (param.letter == '%')
	{
		*str = '%';
		str[1] = '\0';
		return (str);
	}
	if (param.letter == 's')
		return (va_arg(ap, char *));
	free(str);
	return (NULL);
}

char	*poney2(t_arg param, va_list ap)
{
	if (param.letter == 'o')
	{
		if (param.conv != 0)
			return (gestion_arg2(param.conv, 8, '.', ap));
		return (unsigned_get_base(va_arg(ap, int), 8, '.'));
	}
	if (param.conv == 'O')
	{
		if (param.conv != 0)
			return (gestion_arg2(param.conv, 8, '.', ap));
		return (unsigned_get_base(va_arg(ap, long), 8, '.'));
	}
	if (param.letter == 'u')
	{
		if (param.conv != 0)
			return (gestion_arg2(param.conv, 10, '.', ap));
		return (unsigned_get_base(va_arg(ap, unsigned int), 10, '.'));
	}
	if (param.letter == 'U')
	{
		if (param.conv != 0)
			return (gestion_arg2(param.conv, 10, '.', ap));
		return (unsigned_get_base(va_arg(ap, unsigned long), 10, '.'));
	}
	return (poney3(param, ap));
}

char	*get_string(t_arg param, va_list ap)
{
	if (param.letter == 'd' || param.letter == 'i')
	{
		if (param.conv != 0)
			return (gestion_arg(param.conv, 10, '.', ap));
		return (get_base(va_arg(ap, int), 10, '.'));
	}
	if (param.letter == 'D')
	{
		if (param.conv != 0)
			return (gestion_arg(param.conv, 10, '.', ap));
		return (get_base(va_arg(ap, long), 10, '.'));
	}
	if (param.letter == 'x' || param.letter == 'X')
	{
		if (param.conv != 0)
			return (gestion_arg2(param.conv, 16, param.letter - 23, ap));
		return (unsigned_get_base(va_arg(ap, unsigned int), 16, param.letter - 23));
	}
	if (param.letter == 'p')
		return (ft_strcat("0x", unsigned_get_base(va_arg(ap, unsigned long), 16, 'a')));
	return (poney2(param, ap));
}
