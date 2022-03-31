/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_treatment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:39:58 by atenhune          #+#    #+#             */
/*   Updated: 2022/03/25 20:37:23 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_flag_treatment(char *s, t_flags *flags)
{
	int		i;
	char	*new;

	// printf("(%s)\n", s);
	i = 0;
	if (flags->original_len < flags->width)
		new = ft_strnew(flags->width);
	else
		return (s);
	while (i < flags->width - flags->original_len)
		new[i++] = '0';
	// if (flags->negative == 1)
	// {
	// 	new[0] = '-';
	// 	new[i++] = '0';
	// 	ft_memmove(&new[i], &s[flags->width - flags->original_len + 1], flags->original_len);
	// }
	// else
		ft_memmove(&new[i], &s[flags->width - flags->original_len], flags->original_len);
	ft_memdel((void*)&s);
	return (new);
}

int	strlen_minus_space(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if(s[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

char	*plus_flag_treatment(char *s, t_flags *flags)
{
	char	*new;
	int		i;
	int		minus;

	new = NULL;
	i = 0;
	minus = 0;
	// printf("'%s'\n", s);
	if (flags->negative == 1)
		return(s);
	// if (flags->width > flags->original_len && flags->minus)
	// 	minus = 1;
	while (!ft_isdigit(s[i]))
		i++;
	if(i == 0)
	{
		if (!(flags->zero && flags->width > flags->original_len))
			ft_memmove(&s[1], &s[0], strlen_minus_space(s));
		s[0] = '+';
	}
	else
		s[i - 1] = '+';
	return (s);
}

// char	*width_treatment(char *s, t_flags *flags)
// {
// 	char	*ret;
// 	int		i;
// 	int		j;

// 	// printf("[%s]\n", s);
// 	i = 0;
// 	j = 0;
// 	if (flags->width > flags->original_len)
// 	{
// 		ret = ft_strnew(flags->width + 2);
// 		while (i < flags->width - flags->original_len)
// 			ret[i++] = ' ';
// 	}
// 	else
// 		ret = ft_strnew(flags->original_len + 2);
// 	while(s[j])
// 		ret[i++] = s[j++];
// 	ft_memdel((void*)&s);
// 	// free(s);
// 	return(ret);
// }
char	*width_treatment(char *s, t_flags *flags)
{
	int		i;
	int		j;

	// printf("[%s]\n", s);
	i = 0;
	j = flags->width - flags->original_len;
	if (flags->width > flags->original_len)
	{
		ft_memmove(&s[j], &s[0], flags->original_len);
		while (i < j)
			s[i++] = ' ';
	}
	return (s);
}

// char *precision_treatment(char *s, t_flags *flags)
// {
// 	char	*ret;
// 	int		i;
// 	int		j;

// 	ret = NULL;
// 	i = 0;
// 	j = 0;
// 	// printf("(%s) (%d)\n", s, flags->width);
// 	if (flags->precision <= flags->original_len || flags->precision <= flags->width || flags->spec == 's')
// 		return (s);
// 	while (s[j] == ' ')
// 		j++;
// 	ret = ft_strnew(flags->precision + 2);
// 	while (i < flags->precision - flags->original_len)
// 		ret[i++] = '0';
// 	while(s[j])
// 		ret[i++] = s[j++];
// 	ft_memdel((void*)&s);
// 	printf("ret : (%s)\n", ret);
// 	return(ret);
// }
char *precision_treatment(char *s, t_flags *flags)
{
	int		from;
	int		to;
	int		i;

	from = flags->width - flags->original_len;
	to = flags->precision - flags->original_len;
	i = 0;
	// printf("(%s) (%d)\n", s, flags->width);
	if (flags->precision <= flags->original_len || flags->precision <= flags->width || flags->spec == 's')
		return (s);
	if (from < 0)
		from = 0;
	ft_memmove(&s[to], &s[from], flags->original_len);
	while (i < to)
		s[i++] = '0';
	return(s);
}

char	*minus_flag_treatment(char *s, t_flags *flags)
{
	int	i;

	i = flags->original_len;
	if (flags->original_len > flags->width)
		return (s);
	ft_memmove(&s[0], &s[flags->width - flags->original_len], flags->original_len);
	while (i < flags->width)
		s[i++] = ' ';
	return (s);
}

char	*space_flag_treatment(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	// printf("(%s)\n", s);
	if (flags->plus == 1 || flags->negative == 1)
		return (s);
	else if (flags->precision > flags->width || (flags->precision < flags->original_len > flags->width))
	{
		ft_memmove(&s[1], &s[0], ft_strlen(s));
		s[0] = ' ';
	}
	else if ((flags->original_len < flags->width > flags->precision))
		s[0] = ' ';
	// else if (flags->dot && flags->precision > flags->width)
	// {
	// 	ft_memmove(&s[1], &s[0], ft_strlen(s));
	// 	s[0] = ' ';
	// }
	// else
	// {
	// 	while (s[i] == '0' || s[i] == ' ')
	// 		i++;
	// 	if (i == 0)
	// 	{
	// 		ft_memmove(&s[1], &s[0], flags->original_len);
	// 		s[0] = ' ';
	// 	}
	// 	else
	// 		s[i - 1] = ' ';
	// }
	return (s);
}

char *octal_hashtag(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->precision <= flags->original_len)
	{
		if (s[0] != ' ')
		{
			ft_memmove(&s[1], &s[0], flags->original_len);
			s[0] = '0';
		}
		else
		{
			while (s[i] == ' ')
				i++;
			s[i - 1] = '0';
		}
	}
	return (s);
}

char	*hashtag_flag_treatment(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	// printf("|%s|", s);
	if (flags->spec == 'o')
		return (octal_hashtag(s, flags));
	if (s[i] == ' ')
	{
		while(s[i] == ' ' && s[i])
			i++;
		if (i < 2)
		{
			ft_memmove(&s[i + 1], &s[i], ft_strlen(&s[i]));
			s[0] = '0';
			s[1] = flags->spec;
		}
		else
		{
			s[i - 2] = '0';
			s[i - 1] = flags->spec;
		}
	}
	else if (flags->precision <= flags->original_len)
	{
		ft_memmove(&s[2], &s[0], flags->original_len);
		s[0] = '0';
		s[1] = flags->spec;
	}
	else
	{
		// while(ft_isdigit(s[i]) && s[i])
		// 	i++;
		// if (i == 0)
		// 	ft_memmove(&s[2], &s[0], i);
		ft_memmove(&s[2], &s[0], ft_strlen(s));
		s[0] = '0';
		s[1] = flags->spec;
	}
	return (s);
}

char	*dot_for_numbers_minus(char *s, t_flags *flags)
{
	int	shift_1;
	int	shift_2;
	int	i;
	shift_1 = flags->precision - flags->original_len;
	shift_2 = ft_strlen(s) - flags->original_len;
	i = 0;
	if (flags->precision > flags->original_len)
	{
		ft_memmove(&s[shift_1], &s[shift_2], flags->original_len);
		while (i < shift_1)
			s[i++] = '0';
	}
	else
		ft_memmove(&s[0], &s[shift_2], flags->original_len);
	i += flags->original_len;
	while(s[i])
		s[i++] = ' ';
	flags->minus = 0;
	return (s);
}

char	*dot_for_numbers(char *s, t_flags *flags)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(s) - 1;
	// printf("(%s)\n", s);
	// printf("i : %d\n", i);
	if (flags->minus)
		return (dot_for_numbers_minus(s, flags));
	while(i >= 0)
	{
		// printf("j : %d ol : %d  pr : %d\n", j, flags->original_len, flags->precision);
		if (j < flags->original_len)
		{
			i--;
			j++;
		}
		else if (j >= flags->original_len && j < flags->precision)
		{
			s[i] = '0';
			j++;
			i--;
		}
		else
		{
			s[i] = ' ';
			i--;
			j++;
		}
	}
	flags->zero = 0;
	return (s);
}

char	*dot_for_strings(char *s, t_flags *flags)
{
	int		i;
	int		j;
	char	filler;

	i = 0;
	j = 0;
	filler = ' ';
	if (flags->zero)
		filler = '0';
	// printf("(%d)\n", flags->width);
	if(flags->precision < flags->original_len && flags->minus)
	{
		while (i < flags->precision)
		{
			s[i] = flags->str[i];
			i++;
		}
		if (flags->width > flags->original_len)
		{
			while (s[i])
				s[i++] = filler;
		}
		if (i < flags->width)
		{
			while (i < flags->width)
				s[i++] = filler;
		}
		while (s[i])
			s[i++] = '\0';

		flags->minus = 0;
	}
	else if (flags->precision < flags->original_len)
	{
		if(flags->width > flags->precision)
		{
			while (i < flags->width)
			{
				if (i >= flags->width - flags->precision)
					s[i++] = flags->str[j++];
				else
					s[i++] = filler;
			}
		}
		else
		{
			while(i < flags->precision)
				s[i++] = flags->str[j++];
		}
		while (s[i])
			s[i++] = '\0';
	}
	// printf("'%s'\n", s);
	return (s);
}

char	*dot_flag_treatment(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	// printf("'%s'\n", s);
	if (flags->spec != 'f' && flags->spec != 's')
		return (dot_for_numbers(s, flags));
	if (flags->spec == 's')
	{
		return(dot_for_strings(s, flags));
	}
	return (s);
}

char	*if_negative(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	// printf("(%s)", s);
	if (flags->width > flags->precision)
	{
		while(s[i] == ' ')
			i++;
		if (i == 0)
		{
			if (!flags->zero)
			{
				if(flags->original_len >= flags->width)
					ft_memmove(&s[1], &s[0], ft_strlen(s));
				else
					ft_memmove(&s[1], &s[0], ft_strlen(s) - 1);
			}
			else if (flags->original_len >= flags->width)
				ft_memmove(&s[1], &s[0], ft_strlen(s));
			s[0] = '-';
		}
		else
			s[i - 1] = '-';
	}
	else
	{
		ft_memmove(&s[1], &s[0], ft_strlen(s));
		s[0] = '-';
	}
	return (s);
}

void	flag_modifier(t_flags *flags)
{
	if (flags->spec != 'o' && flags->spec != 'x' && flags->spec != 'X')
		flags->hashtag = 0;
	if (flags->minus)
		flags->zero = 0;
	if (flags->spec == '%')
	{
		flags->space = 0;
		flags->hashtag = 0;
	}
	if (flags->spec == 'c')
	{
		flags->space = 0;
		flags->plus = 0;
		flags->dot = 0;
		flags->precision = 0;
	}
	if (flags->spec == 's')
	{
		flags->hashtag = 0;
		flags->space = 0;
	}
	if (flags->spec == 'p')
	{
		flags->space = 0;
		flags->plus = 0;
	}
}

char	*flag_trafficker(char *s, t_flags *flags)
{

	// printf("[%d]\n", flags->precision);
	flag_modifier(flags);
	s = width_treatment(s, flags);
	s = precision_treatment(s, flags);
	if (flags->dot)
		s = dot_flag_treatment(s, flags);
	if (flags->minus)
		s = minus_flag_treatment(s, flags);
	if (flags->zero == 1 && flags->minus != 1)
		s = zero_flag_treatment(s, flags);
	if (flags->plus)
		s = plus_flag_treatment(s, flags);
	if (flags->space == 1 && flags->plus != 1)
		s = space_flag_treatment(s, flags);
	if (flags->hashtag)
		s = hashtag_flag_treatment(s, flags);
	if (flags->negative)
		s = if_negative(s, flags);
	return (s);
	// exit(0);
}



















