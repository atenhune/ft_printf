/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:36:58 by antti             #+#    #+#             */
/*   Updated: 2022/03/30 17:49:19 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	float_width(t_flags *flags, int len)
{
	int		i;
	int		dot;
	char	c;

	i = 0;
	dot = 1;
	// printf("(%d)", len);
	if (flags->precision == 0 && !flags->hashtag)
		dot = 0;
	c = ' ';
	if (flags->zero)
		c = '0';
	while (i < flags->width - flags->precision - len - dot - flags->negative - flags->plus)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	float_rounder(long double nbr)
{
	long double			temp1;
	long double			comp;
	unsigned long long	temp2;

	temp1 = nbr;
	temp2 = nbr;
	comp = 0.5;
	if (temp2 != 0)
		temp1 = nbr - temp2;
	if (comp == temp1)
	{
		if (temp2 % 2 != 0)
			ft_putnbr(temp2 + 1);
		else
			ft_putnbr(temp2);
	}
	else if (temp1 < comp)
		ft_putnbr(temp2);
	else
		ft_putnbr(temp2 + 1);
	return (1);
}

int	float_zero_precision(long double nbr, t_flags *flags)
{
	unsigned long long	temp;
	char				*s;
	int					ret;

	temp = nbr;
	s = ft_itoa(temp, 30);
	ret = write(1, &s[0], ft_strlen(s) - 1);
	temp = s[ft_strlen(s) - 1] - '0';
	s[ft_strlen(s) - 1] = '0';
	nbr = nbr - ft_atoi(s);
	ft_memdel((void *)&s);
	ret += float_rounder(nbr);
	if (flags->hashtag)
		ret += write(1, ".", 1);
	return (ret);
}
