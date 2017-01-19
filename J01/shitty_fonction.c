/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shitty_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:32:00 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 15:35:39 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_space(t_arg p)
{
	int		i;
	int		to_print;

	i = 0;
	if (p.space < 0)
		p.space = -p.space;
	if (p.point == 1 && p.pres == 0)
		return (p.space);
	to_print = p.space - get_value(p);
	if (p.letter != 's' && p.letter != 'c')
		to_print -= p.pres > ft_strlen(p.str) ? p.pres - get_value(p) : 0;
	to_print -= p.pos;
	to_print -= p.neg;
	if (check_oOh(p) == 1)
		to_print -= 1;
	i = p.pres > ft_strlen(p.str) ? 0 : p.pres - ft_strlen(p.str);
	if (i < 0 || p.letter == 'c' || p.letter == 's')
		i = 0;
	to_print -= i;
	return (to_print > 0 ? to_print : 0);
}

int		nb_pres(t_arg p)
{
	int		i;
	int		to_print;

	i = 0;
	if (p.letter == 's' || p.letter == 'c')
		return (0);
	to_print = p.pres - ft_strlen(p.str);
//	while (i++ < to_print)
//		ft_putchar('0');
	return (to_print > 0 ? to_print : 0);
}

int		put_shit(int nb, char c)
{
	int		i;

	i = 0;
	while (i++ < nb)
		ft_putchar(c);
	return (nb);
}
