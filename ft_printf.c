/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:24 by antti             #+#    #+#             */
/*   Updated: 2022/03/31 12:28:55 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"


int	print_length(va_list args, const char *str, int i, t_flags flags)
{
	if (str[i] == 'L')
		return (specifiers(args, str[i + 1], flags));
	while (str[i] == 'l' || str[i] == 'h')
		i++;
	return (specifiers(args, str[i], flags));
}

t_flags flags_initializer(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hashtag = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.negative = 0;
	flags.original_len = 0;
	flags.index_jump = 0;
	flags.dot = 0;
	flags.i = 0;
	flags.precision = 0;
	flags.length[0] = 0;
	flags.length[1] = 0;
	return (flags);
}

void	length_catcher(const char *s, t_flags *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flags->index_jump = 0;
	while (*s == 'l' || *s == 'h' || *s == 'L' || *s =='j' || *s =='t' || *s =='z')
	{
		if ((*s != 'z' || *s !='j' || *s !='t') && j == 0)
		{
			if (*s == 'l' && flags->length[0] == 'l')
				flags->length[1] = *s;
			else if (*s == 'l')
				flags->length[0] = *s;
			else if (flags->length[0] == 'h' && *s == 'h')
				flags->length[1] = *s;
			else if (flags->length[0] != 'l' && *s == 'h')
				flags->length[0] = *s;
			else if (*s == 'L')
				flags->length[0] = 'L';
		}
		if (*s == 'z' || *s =='j' || *s =='t')
		{
			flags->length[0] = 'l';
			flags->length[1] = 'l';
			j++;
		}
		s++;
		i++;
	}
	flags->index_jump = i;
}

void flag_catcher(const char *s, t_flags *flags)
{
	int ret;

	ret = 0;
	while (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
	{
		if (*s == '+')
			flags->plus = 1;
		if (*s == '-')
			flags->minus = 1;
		if (*s == '#')
			flags->hashtag = 1;
		if (*s == ' ')
			flags->space = 1;
		if (*s == '0')
			flags->zero = 1;
		if (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
			ret++;
		s++;
	}
	flags->index_jump = ret;
}
void precision_catcher(const char *s, t_flags *flags, va_list args)
{
	int ret;

	ret = 0;
	while (*s == '.' || *s == '*')
	{
		if (*s == '.')
		{
			flags->dot = 1;
			ret++;
		}
		if (*s == '*')
		{
			ret++;
			wildcard_for_precision(flags, args);
			break;
		}
		s++;
	}
	flags->index_jump = ret;
}

int	specifier_sorter(va_list args, char spec, t_flags flags)
{
	if (spec == 'D' || spec == 'I' || spec == 'U' || spec == 'O')
	{
		flags.length[0] = 'l';
		flags.length[1] = '\0';
		spec = spec + 32;
	}
	if ((flags.length[0] == 'l' && flags.length[1] == 'l') || flags.length[0] == 'L')
		return(ll_specifiers(args, spec, flags));
	if (flags.length[0] == 'l')
		return (l_specifiers(args, spec, flags));
	return (specifiers(args, spec, flags));
}

int	index_counter(const char *s)
{
	int ret;

	ret = 0;
	while(s[ret] && ft_isdigit(s[ret]))
		ret++;
	return (ret);
}

void	wildcard_for_precision(t_flags *flags, va_list args)
{
	flags->precision = va_arg(args, int);
	if (flags->precision < 0)
	{
		flags->precision = 0;
		flags->dot = 0;
	}
}

void	wildcard_for_width(t_flags *flags, va_list args)
{
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	flags->index_jump = 1;
}

int	blaablaa(const char *s, t_flags *flags, va_list args)
{
	int	ret;
	int	temp;

	ret = 0;
	while(*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0'
	|| *s == '.' || *s == '*' || *s == 'l' || *s == 'h' || *s == 'L' 
	|| *s == 'j' || *s == 't' || *s == 'z' || ft_isdigit(*s))
	{
		flags->index_jump = 0;
		temp = 0;
		if (*s == '+' || *s == '-' || *s == '#' || *s == ' ' || *s == '0')
			flag_catcher(&(*s), flags);
		else if (*s == 'l' || *s == 'h' || *s == 'L' || *s =='j' || *s =='t' || *s =='z')
			length_catcher(&(*s), flags);
		else if (*s == '.')
		{
			precision_catcher(&(*s), flags, args);
			if ((*(s + flags->index_jump - 1)) != '*')
				flags->precision = ft_atoi(&(*(s + flags->index_jump)));
			temp = index_counter(&(*(s + flags->index_jump)));
			s += temp;
		}
		else if (ft_isdigit(*s))
		{
			flags->width = ft_atoi(&(*(s)));
			temp = index_counter(&(*(s)));
			s += temp;
		}
		else if (*s == '*')
		{
			wildcard_for_width(flags, args);
		}
		s += flags->index_jump;
		ret += flags->index_jump;
		ret += temp;
	}
	// printf("width : [%d]\tprecision : [%d]\n", flags->width, flags->precision);
	// exit(0);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;
	t_flags	flags;
	
	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			flags = flags_initializer();
			i++;
			i += blaablaa(&str[i], &flags, args);
			flags.index_jump = specifier_sorter(args, str[i], flags);
			if (flags.index_jump != -1)
			{
				i++;
				ret += flags.index_jump;
			}
		}
		else if (str[i] != '%')
			ret += write(1, &str[i++], 1);
		else
			i++;
	}
	va_end(args);
	return (ret);
}
