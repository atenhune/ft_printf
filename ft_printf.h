/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:18:49 by antti             #+#    #+#             */
/*   Updated: 2022/03/30 17:44:12 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h> // poista !!!!!!!!

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		hashtag;
	int		zero;
	int		width;
	int		precision;
	int		dot;
	int		index_jump;
	int		negative;
	int		original_len;
	int		i;
	char	length[2];
	char	*str;
	char	spec;

}	t_flags;

int	ft_printf(const char *str, ...);
int	print_chars(int c, t_flags flags);
int	print_str(char *str, t_flags flags);
int	print_signed_nbr(long long int nbr, t_flags flags);
int	print_unsigned_nbr(unsigned long long nbr, t_flags flags);
int print_hex(unsigned long long nbr, const char form, t_flags flags);
int	print_float(double nbr, t_flags flags);
int	print_pointer(unsigned long long pointer, t_flags flags);
int	print_octal(unsigned long long int nbr, t_flags flags);
int uint_len(unsigned int nbr);
int	specifiers(va_list args, const char spec, t_flags flags);
int	l_specifiers(va_list args, const char spec, t_flags flags);
int	ll_specifiers(va_list args, const char spec, t_flags flags);
int	h_specifiers(va_list args, const char spec, t_flags flags);
int	hh_specifiers(va_list args, const char spec, t_flags flags);
char	*flag_trafficker(char *s, t_flags *flags);
int	ull_len(unsigned long long nbr);
int	max_space(t_flags *flags);
int	strlen_minus_space(char *s);
void	wildcard_for_precision(t_flags *flags, va_list args);
int	float_printer(long double nbr, t_flags flags);
int	float_width(t_flags *flags, int len);
int	float_rounder(long double nbr);
int	float_zero_precision(long double nbr, t_flags *flags);

void	ft_bzero(void *s, size_t n);
char	*ft_itoa(unsigned long long int n, int space);
void	ft_putchar(char c);
char	*ft_strnew(size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_memdel(void **ap);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_putstr(const char *s);
char	*ft_strcat(char *s1, const char *s2);
void	ft_putnbr(unsigned long long n);

# endif