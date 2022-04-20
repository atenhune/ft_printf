/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:58:01 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/20 12:29:31 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_putnbr(unsigned long long n)
{
	if (n >= 10)
	{
		print_putnbr(n / 10);
		print_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
