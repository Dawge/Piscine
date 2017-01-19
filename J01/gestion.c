/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:57:08 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 15:50:23 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		check_diD(char c)
{
	if (c == 'D' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

int		check_xXh(t_arg p)
{
	if ((p.letter == 'x' || p.letter == 'X') && p.hash == 1)
		return (1);
	return (0);
}

int		check_oOh(t_arg p)
{
	if ((p.letter == 'o' || p.letter == 'O') && p.hash == 1)
		return (1);
	return (0);
}

char	*abs_string(char *str)
{
	char	*cpy;
	char	*to_return;

	to_return = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!to_return)
		return (NULL);
	cpy = to_return;
	if (*str)
		str++;
	while (*str)
	{
		*cpy = *str;
		str++;
		cpy++;
	}
	*cpy = '\0';
	return (to_return);
}

t_arg	set_params(t_arg params)
{
	char	*cpy;

	cpy = params.str;
	params.cha = *cpy;
	if (params.neg == 1 && params.space > 0)
//	if (check_diD(params.letter) == 0 && params.neg == 1 && params.space > 0)
		params.space = -params.space;
	if (ft_atoi(params.str) >= 0)
		params.neg = 0;
	if (ft_atoi(params.str) < 0 && check_diD(params.letter) == 1)
	{
		params.neg = 1;
		params.pos = 0;
		params.str = abs_string(params.str);
	}
	if (params.space != 0 || params.pos != 0 || params.neg != 0)
		params.brt = 0;
	if (params.letter == 'c' || params.letter == 's')
	{
		params.neg = 0;
		params.pos = 0;
	}
	return (params);
}
