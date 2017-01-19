/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:58:01 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 16:42:00 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		len_base(long nb, int base)
{
	int		len;

	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= base)
	{
		len++;
		nb /= base;
	}
	return (len);
}

char	*get_tab(int base, char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char*)malloc(sizeof(char) * base + 1);
	if (tab)
	{
		while (i < base)
		{
			if (i < 10)
				tab[i] = i + 48;
			else
				tab[i] = c++;
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}

char	*get_base(long nb, int base, char c)
{
	int		len;
	char	*tab;
	char	*str;

	len = 0;
	if (base > 36 || base < 2)
		return (NULL);
	if (base == 10)
		return (ft_itoa(nb));
	tab = get_tab(base, c);
	len = len_base(nb, base);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (nb < 0)
		nb = -nb;
	if (str)
	{
		str[len--] = '\0';
		while (len > 0)
		{
			str[len] = tab[nb % base];
			nb /= base;
			len--;
		}
		str[len] = tab[nb];
		return (str);
	}
	return (NULL);
}

char	*unsigned_get_base(unsigned long long nb, int base, char c)
{
	int		len;
	char	*tab;
	char	*str;

	len = 0;
	if (base > 36 || base < 2)
		return (NULL);
	tab = get_tab(base, c);
	len = len_base(nb, base);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		str[len--] = '\0';
		while (len > 0)
		{
			str[len] = tab[nb % base];
			nb /= base;
			len--;
		}
		str[len] = tab[nb];
		return (str);
	}
	return (NULL);
}
