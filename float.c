/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:11:15 by antti             #+#    #+#             */
/*   Updated: 2022/03/31 11:54:30 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_switcher(t_flags *flags)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->negative)
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if (flags->precision == 0 && flags->dot)
		return (0);
	return (1);
}

int	float_helper1(t_flags *flags, int len, int dot, int ret)
{
	dot = flag_switcher(flags);
	if (flags->negative && (flags->width <= len + flags->precision + dot
			|| flags->minus || flags->zero))
		ret += write(1, "-", 1);
	if (flags->plus && (flags->width <= len + flags->precision + dot
			|| flags->minus || flags->zero))
		ret += write(1, "+", 1);
	if (flags->space)
	{
		ret += write(1, " ", 1);
		flags->width--;
	}
	if (!flags->dot)
		flags->precision = 6;
	if (flags->width > len + flags->precision + dot && !flags->minus)
		ret += float_width(flags, len);
	if (flags->negative && flags->width > len + flags->precision + dot
		&& !flags->minus && !flags->zero)
		ret += write(1, "-", 1);
	if (flags->plus && flags->width > len + flags->precision + dot
		&& !flags->minus && !flags->zero)
		ret += write(1, "+", 1);
	return (ret);
}

int	float_helper2(t_flags *flags, unsigned long long temp, long double nbr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < flags->precision)
	{
		nbr = (nbr - temp) * 10;
		temp = nbr;
		if (i == flags->precision - 1)
		{
			ret += float_rounder(nbr);
			break ;
		}
		ft_putnbr(temp);
		i++;
	}
	ret += i;
	return (ret);
}

int	float_helper3(t_flags *flags,
unsigned long long temp, long double nbr, int len)
{
	int	ret;

	ret = 0;
	ft_putnbr(temp);
	ret += write(1, ".", 1);
	ret += float_helper2(flags, temp, nbr);
	if (flags->minus)
		ret += float_width(flags, len);
	return (ret);
}

int	float_printer(long double nbr, t_flags flags)
{
	unsigned long long	temp;
	int					len;
	int					ret;

	if (1 / nbr < 0)
	{
		nbr = nbr * -1;
		flags.negative = 1;
	}
	temp = nbr;
	len = ull_len(temp);
	ret = len;
	ret += float_helper1(&flags, len, 0, 0);
	if (flags.precision == 0)
	{
		ret -= len;
		ret += float_zero_precision(nbr, &flags);
		if (flags.minus)
			ret += float_width(&flags, len);
		return (ret);
	}
	ret += float_helper3(&flags, temp, nbr, len);
	return (ret);
}
