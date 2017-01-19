/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:14 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 16:24:39 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include"libft.h"

int		print(t_arg p)
{
	int		i;
	char	*cpy;

	i = 0;
	if (p.letter == 'c')
	{
		ft_putchar(p.cha);
		return (1);
	}
	if (p.letter == 's' && p.pres < ft_strlen(p.str) && p.pres > 0)
	{
		cpy = p.str;
		while (i++ < p.pres)
		{
			ft_putchar(*cpy);
			cpy++;
		}
		return (p.pres);
	}
	else
	{
//		if (ft_strlen(p.str) == 0 && p.space > 0)// && (p.letter == 'x' || p.letter == 'X'))
//		{
///			ft_putchar(' ');
//			i = 1;
//		}
		ft_putstr(p.str);
		return (ft_strlen(p.str) + i);
	}
}

int		get_value(t_arg params)
{
	int		value;

	value = 0;
	if (params.letter == 'c' && params.cha == 0)
		return (1);
	if (params.letter == 's')
	{
		if (ft_strlen(params.str) == 0)
			return (0);
		value = params.pres > 0 ? params.pres : (int)ft_strlen(params.str);
	}
	else
		value = (int)ft_strlen(params.str);
	if ((params.letter == 'X' || params.letter == 'x') && (params.hash == 1))
		value += ft_atoi(params.str) != 0 ? 2 : 0;
	return (value);
}

int		stupid_shit(t_arg params)
{
	if (params.hash == 1 && ft_atoi(params.str) != 0)
	{
		ft_putchar('0');
		ft_putchar(params.letter);
		return (2);
	}
	return (0);
}

int		print_shit(t_arg p)
{
	int		tmp;
	int		value;
	int		other_shit;
	int		get_printed;

	p = set_params(p);
	get_printed = 0;
	tmp = p.space;
	if (check_xXh(p) && p.zero == '0')
		get_printed += stupid_shit(p);
	if (check_diD(p.letter) == 1 && p.pos == 1 && p.zero == '0')
		ft_putchar('+');
	if (p.zero == '0' && p.neg == 1)
	{
		ft_putchar('-');
		get_printed++;
	}
	if (tmp > 0)
		get_printed += put_shit(nb_space(p), p.zero);
	if (check_oOh(p))
	{
		get_printed++;
		ft_putchar('0');
	}
	if (p.brt == 1 && p.letter == 'd')
	{
		ft_putchar(' ');
		get_printed++;;
	}
	if (p.zero == ' ' && p.neg == 1)
	{
		ft_putchar('-');
		get_printed++;
	}
	if (check_diD(p.letter) == 1 && p.pos == 1 && p.zero != '0')
		ft_putchar('+');
	get_printed += put_shit(nb_pres(p), '0');
	if (check_xXh(p) && p.zero == ' ')
		get_printed += stupid_shit(p);
	if (!(p.point == 1 && p.pres == 0) || p.letter == '%')
		get_printed += print(p);
	else
	{
		if (p.letter == 'o' || p.letter == 'O')
		{
			ft_putchar(' ');
			get_printed++;
		}
	}
	if (tmp < 0)
		get_printed += put_shit(nb_space(p), p.zero);
	return (get_printed + p.pos);
}
