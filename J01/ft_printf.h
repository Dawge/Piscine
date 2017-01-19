/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:02:34 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/19 16:35:55 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_arg
{
	int		neg;
	char	cha;
	int		pos;
	int		brt;
	int		hash;
	int		conv;
	int		pres;
	char	*str;
	int		space;
	char	zero;
	int		point;
	char	letter;
}				t_arg;

int			check_diD(char c);
int			check_xXh(t_arg p);
int			check_oOh(t_arg p);
int			nb_space(t_arg p);
int			nb_pres(t_arg p);
int			put_shit(int nb, char c);
int			len_base(long nb, int base);
char		*get_base(long nb, int base, char c);
char		*unsigned_get_base(unsigned long long nb, int base, char c);
int			ft_printf(const char *format, ...);
char		*get_string(t_arg param, va_list ap);
int			print_shit(t_arg params);
char		*abs_string(char *str);
int			get_value(t_arg params);
t_arg		set_params(t_arg params);

#endif
