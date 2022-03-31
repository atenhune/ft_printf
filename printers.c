/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:55:21 by antti             #+#    #+#             */
/*   Updated: 2022/03/26 21:23:01 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // poista!!!!!!

int	print_chars(int c, t_flags flags)
{
	char	*a;
	
	a = ft_strnew(1);
	a[0] = c;
	return (print_str(a, flags));
}

int	print_str(char *str, t_flags flags)
{
	int ret;
	char *n_str;
	// printf("[%s]\n", str);
	ret = 0;
	flags.original_len = ft_strlen(str);
	flags.str = ft_strnew(max_space(&flags));
	n_str = ft_strnew(max_space(&flags));
	if (flags.spec == 'c' && str[0] == '\0')
		flags.original_len = 1;
	if (str == NULL)
	{
		ft_strcpy(flags.str, "(null)");
		ft_strcpy(n_str, "(null)");
	}
	else
	{
		ft_strcpy(flags.str, str);
		ft_strcpy(n_str, str);
	}
	n_str = flag_trafficker(n_str, &flags);
	if (flags.spec == 'c' && str[0] == '\0' && flags.minus)
		ret += write(1, &n_str[0], ft_strlen(&n_str[1]) + 1);
	else if (flags.spec == 'c' && str[0] == '\0')
		ret += write(1, &n_str[0], ft_strlen(n_str) + 1);
	else
		ret += write(1, &n_str[0], ft_strlen(n_str));
	if (flags.spec == 'c')
		ft_memdel((void*)&str);
	ft_memdel((void*)&flags.str);
	ft_memdel((void*)&n_str);
	return (ret);
}

long long	signed_hh_converter(long long nbr, t_flags *flags)
{
	signed char	a;
	short int	b;

	a = 0;
	b = 0;
	if(flags->length[0] == 'h' && flags->length[1] == 'h')
	{
		a = nbr;
		nbr = a;
	}
	else
	{
		b = nbr;
		nbr = b;
	}
	return (nbr);
}

int	max_space(t_flags *flags)
{
	if (flags->original_len >= flags->width && flags->original_len >= flags->precision)
		return(flags->original_len + 2);
	if (flags->width >= flags->precision)
		return (flags->width + 2);
	return(flags->precision + 2);
}

int	print_signed_nbr(signed long long nbr, t_flags flags)
{
	int ret;
	char *str;
	unsigned long long n;
	// printf("(%c)", flags.length[0]);
	if(flags.length[0] == 'h')
		nbr = signed_hh_converter(nbr, &flags);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		flags.negative = 1;
	}
	n = nbr;
	flags.original_len = ull_len(n);
	str = ft_itoa(n, max_space(&flags));
	if (nbr == 0 && flags.precision == 0 && flags.dot)
	{
		str[0] = '\0';
		flags.original_len = 0;
	}
	str = flag_trafficker(str, &flags);
	ret = write(1, &str[0], ft_strlen(str));
	ft_memdel((void*)&str);
	return (ret);
}

// int uint_len(unsigned int nbr)
// {
// 	int ret;
// 	ret = 0;
// 	if (nbr == 0)
// 		return (0);
// 	while (nbr != 0)
// 	{
// 		nbr /= 10;
// 		ret++;
// 	}
// 	return (ret);
// }

int	ull_len(unsigned long long nbr)
{
	int	ret;

	ret = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}

unsigned long long	unsigned_hh_converter(unsigned long long nbr, t_flags *flags)
{
	unsigned char		a;
	unsigned short int	b;

	a = 0;
	b = 0;
	if(flags->length[0] == 'h' && flags->length[1] == 'h')
	{
		a = nbr;
		nbr = a;
	}
	else
	{
		b = nbr;
		nbr = b;
	}
	return (nbr);
}

int	print_unsigned_nbr(unsigned long long nbr, t_flags flags)
{
	char	*str;
	int		ret;

	if(flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	flags.space = 0;
	flags.plus = 0;
	flags.original_len = ull_len(nbr);
	str = ft_itoa(nbr, max_space(&flags));
	if (nbr == 0 && flags.precision == 0 && flags.dot)
	{
		str[0] = '\0';
		flags.original_len = 0;
	}
	str = flag_trafficker(str, &flags);
	ret = write(1, &str[0], ft_strlen(str));
	ft_memdel((void*)&str);
	return (ret);
}

void	hex_creator(unsigned long long nbr, const char spec, t_flags *flags)
{
	if (nbr >= 16)
	{
		hex_creator(nbr / 16, spec, flags);
		hex_creator(nbr % 16, spec, flags);
	}
	else
	{
		if(nbr <= 9)
			flags->str[flags->i++] = nbr + '0';
		else
		{
			if (spec == 'x')
				flags->str[flags->i++] = (nbr - 10 + 'a');
			if (spec == 'X')
				flags->str[flags->i++] = (nbr - 10 + 'A');
		}
	}
}
char	*pointer_addon(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	// printf("[%s]\n", s);
	if(flags->width > flags->precision && flags->width > flags->original_len)
	{
		while (s[i] == ' ')
			i++;
		if (i == 0)
			ft_memmove(&s[2], &s[0], strlen_minus_space(s));
		if (i == 1)
			ft_memmove(&s[2], &s[1], strlen_minus_space(s));
		if (i > 1)
		{
			s[i - 2] = '0';
			s[i - 1] = 'x';
			return (s);
		}
		s[0] = '0';
		s[1] = 'x';
	}
	else
	{
		ft_memmove(&s[2], &s[0], ft_strlen(s));
		s[0] = '0';
		s[1] = 'x';
	}
	return (s);
}

int	print_hex(unsigned long long nbr, const char spec, t_flags flags)
{
	int	ret;
	int	space;

	space = 20;
	if(flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	if (max_space(&flags) > space)
		space = max_space(&flags);
	flags.str = ft_strnew(space);
	if (nbr == 0)
		flags.hashtag = 0;
	if (!(nbr == 0 && flags.precision == 0 && flags.dot))
		hex_creator(nbr, spec, &flags);
	flags.original_len = ft_strlen(flags.str);
	flags.str = flag_trafficker(flags.str, &flags);
	if (flags.spec == 'p')
		flags.str = pointer_addon(flags.str, &flags);
	ret = write(1, &flags.str[0], ft_strlen(flags.str));
	ft_memdel((void*)&flags.str);
	return (ret);
}

int	float_helper(long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int print_float(double nbr, t_flags flags)
{
	long long	temp;
	int			i;
	int			size;

	i = 0;
	temp = nbr;
	// printf("%f\n", nbr);
	size = float_helper(temp);
	print_signed_nbr(temp, flags);
	write(1, ".", 1);
	while (i < 6)
	{
		// if (i == size)
		nbr = nbr * 10;
		temp = nbr;
		print_signed_nbr(temp % 10, flags);
		i++;
	}
	return (size + 7);
}

int	print_pointer(unsigned long long pointer, t_flags flags)
{
	int	ret;
	
	ret = print_hex(pointer, 'x', flags);
	return (ret);
}

void	octal_creator(unsigned long long int nbr, t_flags *flags)
{
	if (nbr >= 8)
	{
		octal_creator(nbr / 8, flags);
		octal_creator(nbr % 8, flags);
	}
	else
		flags->str[flags->i++] = nbr + '0';
}

int	print_octal(unsigned long long int nbr, t_flags flags)
{
	int	ret;
	int	space;

	space = 25;
	if(flags.length[0] == 'h')
		nbr = unsigned_hh_converter(nbr, &flags);
	if (max_space(&flags) > space)
		space = max_space(&flags);
	flags.str = ft_strnew(space);
	if (!(nbr == 0 && flags.precision == 0 && flags.dot))
		octal_creator(nbr, &flags);
	if ((nbr == 0 && flags.dot && flags.precision != 0) || (nbr ==0 && !flags.dot))
		flags.hashtag = 0;
	flags.original_len = ft_strlen(flags.str);
	flags.str = flag_trafficker(flags.str, &flags);
	ret = write(1, &flags.str[0], ft_strlen(flags.str));
	ft_memdel((void*)&flags.str);
	return(ret);
}