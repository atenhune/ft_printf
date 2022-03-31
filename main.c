/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:51:36 by atenhune          #+#    #+#             */
/*   Updated: 2022/03/31 12:30:24 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char	*s = "JEE JEE TAA TOIMII!!";
	char *s2 = "moi";
	char *s3 = "hei";
	int		d = 123;
	int		d2 = -123;
	int		ret;
	unsigned int u = 1234567;
	float	f = 123.1;
	long double Lf = 123.123456;
	int		*p;
	long	ld = -234432;
	long long lld = 21474836500928374;
	long	i = -23423423423423423;
	short hd = 23;
	signed char hhd = 'a';
	char cs = 'a';
	long mitatapahtuu = d;
	wchar_t q = 'w';
	p = &d;
	long long ö = 9223372036854775807;
	int *n;
	long double temp1 =0.001;
	long double temp2 =0.0005;
	long double temp3 =0.000;

	// p = &n;
	// uintptr_t	jep = p;

	// ret = printf("|%*.**d|", -12, -5, 14, 123);
	// printf("\n(%#.o)\n", 0);
	// ret = ft_printf("|%*.**d|", -12, -5, 14, 123);
	// printf("\n(%d)\n", ret);
	// ret = printf("|%llhlhlhlhlhlhllhlhlhl  l hlhlhlhllhlhlhld|",-482512345);
	// printf("\n(%d)\n", ret);
	// ret = ft_printf("|%lld|",-482512345);
	// printf("\n(%d)\n", ret);
	// ret = printf("|%.090s| |%*.**d|\n", "moro", 44, -12, -48, 14);
	// ret = printf("|%.090s| |%*.**d|\n", "moro", 44, 12, 48, 14);
	// printf("\n(%d)\n", ret);
	// ret = printf("|%p|", p);
	// float tupla = 1.234;
	// double testi = tupla * 10000000000 / 10000000000;
	ret = printf("|%+#120.100Lf|\n", 2313.213312);
	printf("(%d)\n", ret);
	ret = ft_printf("|%+#120.100Lf|\n", 2313.213312);
	printf("(%d)\n", ret);
	// printf("(%.100Lf)\n", temp2);
	// printf("(%.100Lf)\n", temp1 - temp2);
	// printf("(%.100Lf)\n", temp2 - temp3);
	// ret = printf("|%1.f|\n", 0.5f);
	// ret = printf("|%2.1f|\n", 1.5f);
	// ret = printf("|%3.2f|\n", 2.5f);
	// ret = printf("|%4.3f|\n", 3.5f);
	// ret = printf("|%5.4f|\n", 4.5f);
	// ret = printf("|%6.5f|\n", 5.5f);
	// ret = printf("|%7.6f|\n", 6.5f);
	// ret = printf("|%8.f|\n", 6.501f);
	// ret = printf("|%9.8f|\n", 8.5f);
	// ret = printf("|%10.9f|\n", 9.5f);
	// ret = printf("|%11.10f|\n", 10.5f);
	// ret = ft_printf("|%1.f|\n", 0.5f);
	// ret = ft_printf("|%2.1f|\n", 1.5f);
	// ret = ft_printf("|%3.2f|\n", 2.5f);
	// ret = ft_printf("|%4.3f|\n", 3.5f);
	// ret = ft_printf("|%5.4f|\n", 4.5f);
	// ret = ft_printf("|%6.5f|\n", 5.5f);
	// ret = ft_printf("|%7.6f|\n", 6.5f);
	// ret = ft_printf("|%8.7f|\n", 7.51f);
	// ret = ft_printf("|%9.8f|\n", 8.5f);
	// ret = ft_printf("|%10.9f|\n", 9.5f);
	// ret = ft_printf("|%11.10f|\n", 10.5f);
	// ret = printf("|%f|\n", 0.001 % 10);
	// ret = printf("|%12.10f|\n", testi);
	// printf("\n(%d)\n", ret);
	// printf("\n(%d)\n", ret);
	// printf("moro %hhD\n", 123456789111);
	// ft_printf("moro %hhD\n", 123456789111);
	// printf("%+023d MORO\n", d);
	// ft_printf("%+023d MORO\n", d);
	// printf("%#.0o\n", 0);
	// ft_printf("%+d MORO\n", d);
	// ret = printf("|%-+1.12d|", 123);
	// printf("\n%d\n", ret);
	// ret = ft_printf("|%-+1.12d|", 123);
	// printf("\n%d\n", ret);
	// printf("|%-5.2s is a string|\n", "this");
	// ft_printf("|%-5.2s is a string|\n", "this");
	// ret = printf("|%hhlld|\n", 123456789111111);
	// printf("(%d)\n", ret);
	// ret = ft_printf("|%hhlld|\n", 123456789111111);
	// printf("(%d)\n", ret);
	// printf("|@moulitest: (%s)|\n", NULL);
	// ft_printf("|@moulitest: (%s)|\n", NULL);
	// ret = ft_printf("%c", 0);
	// printf("\n%d\n", ret);
	// ret = ft_printf("|%.2c|\n", NULL);
	// ret = printf("|%.2c|\n", NULL);
	// printf("%d\n", ret);
	// ret = printf("%  %\n");
	// printf("%d\n", ret);
	// printf("% 023d MORO\n", d);
	// ft_printf("% 023d MORO\n", d);
	// printf("% d MORO\n", d);
	// ft_printf("% d MORO\n", d);
	// printf("% 023d MORO\n", d2);
	// ft_printf("% 023d MORO\n", d2);
	// printf("%u MORO\n", u);
	// ft_printf("%u MORO\n", u);


}
