/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:18:42 by atenhune          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:41 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifiers(va_list args, const char spec, t_flags flags)
{
	flags.spec = spec;
	// printf("\n\n[ spec :%c]\n\n", spec);
	if (spec == 'c')
		return (print_chars(va_arg(args, int), flags));
	else if (spec == 's')
		return (print_str(va_arg(args, char*), flags));
	else if (spec == 'd' || spec == 'i')
		return (print_signed_nbr(va_arg(args, int), flags));
	else if (spec == '%')
		return (print_str("%", flags));
	else if (spec == 'u')
		return (print_unsigned_nbr(va_arg(args, unsigned int), flags));
	else if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(args, unsigned int), spec, flags));
	else if (spec == 'f')
		return (float_printer(va_arg(args, double), flags));
	else if (spec == 'p')
		return (print_pointer(va_arg(args, unsigned long int), flags));
	else if (spec == 'o')
		return (print_octal(va_arg(args, unsigned int), flags));
	return (-1);
}

int	l_specifiers(va_list args, const char spec, t_flags flags)
{
	// printf("\n\n[ spec :%c]\n\n", spec);
	flags.spec = spec;
	if (spec == 'd' || spec == 'i')
		return (print_signed_nbr(va_arg(args, long int), flags));
	else if (spec == 'u')
		return (print_unsigned_nbr(va_arg(args, unsigned long int), flags));
	else if (spec == 'o')
		return (print_octal(va_arg(args, unsigned long int), flags));
	else if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(args, unsigned long int), spec, flags));
	else if (spec == 'f')
		return (float_printer(va_arg(args, double), flags));
	return (-1);
}

int	ll_specifiers(va_list args, const char spec, t_flags flags)
{
	// printf("\n\n[ spec :%c]\n\n", spec);
	flags.spec = spec;
	if (spec == 'd' || spec == 'i')
		return (print_signed_nbr(va_arg(args, long long int), flags));
	else if (spec == 'u')
		return (print_unsigned_nbr(va_arg(args, unsigned long long int), flags));
	else if (spec == 'o')
		return (print_octal(va_arg(args, unsigned long long int), flags));
	else if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(args, unsigned long long int), spec, flags));
	else if (spec == 'f')
		return (float_printer(va_arg(args, long double), flags));
	return (-1);
}

// int	h_specifiers(va_list args, const char spec, t_flags flags)
// {
// 	if (spec == 'd' || spec == 'i')
// 		return (print_signed_nbr(va_arg(args, short), flags));
// 	else if (spec == 'u')
// 		return (print_unsigned_nbr(va_arg(args, unsigned short), flags));
// 	else if (spec == 'o')
// 		return (print_octal(va_arg(args, unsigned short), flags));
// 	else if (spec == 'x' || spec == 'X')
// 		return (print_hex(va_arg(args, unsigned short), spec, flags));
// 	return (0);
// }

// int	hh_specifiers(va_list args, const char spec, t_flags flags)
// {
// 	if (spec == 'd' || spec == 'i')
// 		return (print_signed_nbr(va_arg(args, signed char), flags));
// 	else if (spec == 'u')
// 		return (print_unsigned_nbr(va_arg(args, unsigned char), flags));
// 	else if (spec == 'o')
// 		return (print_octal(va_arg(args, unsigned char), flags));
// 	else if (spec == 'x' || spec == 'X')
// 		return (print_hex(va_arg(args, unsigned char), spec, flags));
// 	return (0);
// }