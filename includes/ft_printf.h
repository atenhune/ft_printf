/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:18:49 by antti             #+#    #+#             */
/*   Updated: 2022/04/20 12:27:24 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

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

int					ft_printf(const char *str, ...);
int					print_chars(int c, t_flags flags);
int					print_str(char *str, t_flags flags);
int					print_signed_nbr(long long int nbr, t_flags flags);
int					print_unsigned_nbr(unsigned long long nbr, t_flags flags);
int					print_hex(unsigned long long nbr,
						const char form, t_flags flags);
int					print_float(double nbr, t_flags flags);
int					print_pointer(unsigned long long pointer, t_flags flags);
int					print_octal(unsigned long long int nbr, t_flags flags);
int					specifiers(va_list args, const char spec, t_flags flags);
int					l_specifiers(va_list args, const char spec, t_flags flags);
int					ll_specifiers(va_list args, const char spec, t_flags flags);
char				*flag_trafficker(char *s, t_flags *flags);
int					ull_len(unsigned long long nbr);
int					max_space(t_flags *flags);
int					strlen_minus_space(char *s);
void				wildcard_for_precision(t_flags *flags, va_list args);
int					float_printer(long double nbr, t_flags flags);
int					float_width(t_flags *flags, int len);
int					float_rounder(long double nbr);
int					float_zero_precision(long double nbr, t_flags *flags);
long double			round_amount(t_flags *flags);
long double			is_there_need_to_round(t_flags *flags,
						long double nbr, long double rounding);
int					flag_switcher(t_flags *flags);
void				wildcard_for_precision(t_flags *flags, va_list args);
void				wildcard_for_width(t_flags *flags, va_list args);
int					format_reader(const char *s, t_flags *flags,
						va_list args, int ret);
int					index_counter(const char *s);
void				precision_catcher(const char *s,
						t_flags *flags, va_list args);
void				flag_catcher(const char *s, t_flags *flags);
void				length_catcher(const char *s, t_flags *flags);
int					print_percent(char *str, t_flags flags);
long long			signed_hh_converter(long long nbr, t_flags *flags);
unsigned long long	unsigned_hh_converter(unsigned long long nbr,
						t_flags *flags);
char				*pointer_addon(char *s, t_flags *flags, int i);
void				octal_creator(unsigned long long int nbr, t_flags *flags);
void				hex_creator(unsigned long long nbr,
						const char spec, t_flags *flags);
char				*minus_flag_treatment(char *s, t_flags *flags);
char				*precision_treatment(char *s, t_flags *flags);
char				*width_treatment(char *s, t_flags *flags);
char				*plus_flag_treatment(char *s, t_flags *flags);
char				*zero_flag_treatment(char *s, t_flags *flags);
char				*space_flag_treatment(char *s, t_flags *flags);
char				*hashtag_flag_treatment(char *s, t_flags *flags);
char				*dot_for_strings(char *s, t_flags *flags);
char				*dot_for_numbers(char *s, t_flags *flags);
char				*dot_flag_treatment(char *s, t_flags *flags);
void				ft_bzero(void *s, size_t n);
char				*better_ft_itoa(unsigned long long int n, int space);
void				ft_putchar(char c);
char				*better_ft_strnew(size_t size);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
char				*ft_strcpy(char *dst, const char *src);
void				print_putnbr(unsigned long long n);

#endif