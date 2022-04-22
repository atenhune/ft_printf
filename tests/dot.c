/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:08:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 18:22:29 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%012.2d\n", 42);
	printf("% 012.4d\n", 42);
	printf("% 0-12.19d\n", 42);
	printf("%012.2d\n", -42);
	printf("% 012.23d\n", -42);
	printf("%012.9d\n", 0);
	printf("%+012.0d\n", 0);
	printf("%-01.21d\n", 0);
	printf("%+02.5d\n", 0);
	printf("%012.2d\n", INT_MAX);
	printf("%+012.12d\n", INT_MAX);
	printf("%+-012.14d\n", INT_MAX);
	printf("%+012.9d\n", INT_MIN);
	printf("%-01.2d\n", INT_MIN);
	printf("%-+012.11d\n", INT_MIN);
	printf("%012.2i\n", 42);
	printf("% 012.2i\n", 42);
	printf("%012.3i\n", -42);
	printf("%0 12.13i\n", -42);
	printf("%012.19i\n", 0);
	printf("%+012.12i\n", 0);
	printf("%-01.12i\n", 0);
	printf("%+02.20i\n", 0);
	printf("%012.1i\n", INT_MAX);
	printf("%+012.12i\n", INT_MAX);
	printf("%+-012.13i\n", INT_MAX);
	printf("%+012.8i\n", INT_MIN);
	printf("%-01.2i\n", INT_MIN);
	printf("%-+012.21i\n", INT_MIN);
	printf("%.0u\n", 0);
	printf("%.u\n", 0);
	printf("%.1u\n", 0);
	printf("%12.11u\n", 0);
	printf("%012.11u\n", 0);
	printf("%02.9u\n", 0);
	printf("%01.2u\n", 0);
	printf("%030.7u\n", 0);
	printf("%-30.13u\n", 0);
	printf("%-030.32u\n", 0);
	printf("%.12u\n", 123);
	printf("%12.2u\n", 12345);
	printf("%012.9u\n", 11);
	printf("%02.21u\n", 65463456);
	printf("%01.22u\n", 3456);
	printf("%030.30u\n", 11324);
	printf("%-30.2u\n", 1234);
	printf("%-030.4u\n", 99912);
	printf("%-030.x\n", 0);
	printf("%#.0x\n", 0);
	printf("%#.2x\n", 0);
	printf("%-30.21x\n", 0);
	printf("%-#30.32x\n", 0);
	printf("%030.2x\n", 0);
	printf("%0#30.5x\n", 0);
	printf("%-030.7x\n", 123);
	printf("%030.3x\n", 432134);
	printf("%03.34x\n", 12312);
	printf("%0#.3x\n", 12312);
	printf("%-030.X\n", 0);
	printf("%-30.1X\n", 0);
	printf("%-#30.2X\n", 0);
	printf("%030.2X\n", 0);
	printf("%-030.32X\n", 123);
	printf("%-0#30.2X\n", 123);
	printf("%030.32X\n", 432134);
	printf("%03.11X\n", 12312);
	printf("%03o\n", 12312);
	printf("%03o\n", 0);
	printf("%#.1o\n", 0);
	printf("%#.o\n", 0);
	printf("%#.2o\n", 0);
	printf("%#03.12o\n", 0);
	printf("%#03.32o\n", 0);
	printf("%0#3.4o\n", 0);
	printf("%-033.11o\n", 0);
	printf("%033.21o\n", 0);
	printf("%03.22o\n", INT_MAX);
	printf("%02.22o\n", UINT_MAX);
	printf("%-030.29o\n", UINT_MAX);
	printf("%-12.2o\n", UINT_MAX);
	printf("%.f\n", 0.0f);
	printf("%.3f\n", 0.0f);
	printf("%.f\n", 1.5f);
	printf("%.f\n", 1.9f);
	printf("%.f\n", 1.1f);
	printf("%.f\n", 0.5f);
	printf("%.f\n", 9.5f);
	printf("%.3f\n", 9.51234f);
	printf("%.3f\n", 9.5555f);
	printf("%.3f\n", 9.559999f);
	printf("%.3f\n", 9.59939f);
	printf("%.3f\n", 9.234234f);
	printf("%.3f\n", 9.734234f);
	printf("%.3f\n", 9.434234f);
	printf("%.7f\n", 9.9999999999f);
	printf("%.8f\n", 9.9999999999f);
	printf("%.10f\n", 9.9999999999f);
	printf("%.3f\n", 0.0005f);
	printf("%.10f\n", 0.0005f);
	printf("%.12f\n", 0.0005f);
	printf("%.12f\n", 9.99999999f);
	printf("%.12f\n", 0.99999999f);
	printf("%.12f\n", 4.99999999f);
	printf("%.14f\n", 4.99499999f);
	printf("%.2f\n", 4.9999435999f);
	printf("%.1f\n", 4.99999999f);
	printf("%.4f\n", 4.99999999f);
	printf("%.4f\n", 19.99999999f);
	printf("%.20f\n", 191231232.99999999f);
	printf("%.30f\n", 191231232.99999999f);
	printf("%.40f\n", 191231232.99999999f);
	printf("%.50f\n", 191231232.99999999f);
	printf("%.f\n", -0.0f);
	printf("%.2f\n", -0.0f);
	printf("%.f\n", -1.5f);
	printf("%.f\n", -1.9f);
	printf("%.f\n", -1.1f);
	printf("%.f\n", -0.5f);
	printf("%.f\n", -9.5f);
	printf("%.3f\n", -9.51234f);
	printf("%.3f\n", -9.5555f);
	printf("%.3f\n", -9.559999f);
	printf("%.3f\n", -9.59939f);
	printf("%.3f\n", -9.234234f);
	printf("%.3f\n", -9.734234f);
	printf("%.3f\n", -9.434234f);
	printf("%.7f\n", -9.9999999999f);
	printf("%.8f\n", -9.9999999999f);
	printf("%.10f\n", -9.9999999999f);
	printf("%.3f\n", -0.0005f);
	printf("%.10f\n", -0.0005f);
	printf("%.12f\n", -0.0005f);
	printf("%.12f\n", -9.99999999f);
	printf("%.12f\n", -0.99999999f);
	printf("%.12f\n", -4.99999999f);
	printf("%.14f\n", -4.99499999f);
	printf("%.2f\n", -4.9999435999f);
	printf("%.1f\n", -4.99999999f);
	printf("%.4f\n", -4.99999999f);
	printf("%.4f\n", -19.99999999f);
	printf("%.Lf\n", 0.0l);
	printf("%.3Lf\n", 0.0l);
	printf("%.Lf\n", 1.5l);
	printf("%.Lf\n", 1.9l);
	printf("%.Lf\n", 1.1l);
	printf("%.Lf\n", 0.5l);
	printf("%.Lf\n", 9.5l);
	printf("%.3Lf\n", 9.51234l);
	printf("%.3Lf\n", 9.5555l);
	printf("%.3Lf\n", 9.559999l);
	printf("%.3Lf\n", 9.59939l);
	printf("%.3Lf\n", 9.234234l);
	printf("%.3Lf\n", 9.734234l);
	printf("%.3Lf\n", 9.434234l);
	printf("%.7Lf\n", 9.9999999999l);
	printf("%.8Lf\n", 9.9999999999l);
	printf("%.10Lf\n", 9.9999999999l);
	printf("%.3Lf\n", 0.0005l);
	printf("%.10Lf\n", 0.0005l);
	printf("%.12Lf\n", 0.0005l);
	printf("%.12Lf\n", 9.99999999l);
	printf("%.12Lf\n", 0.99999999l);
	printf("%.12Lf\n", 4.99999999l);
	printf("%.14Lf\n", 4.99499999l);
	printf("%.2Lf\n", 4.9999435999l);
	printf("%.1Lf\n", 4.99999999l);
	printf("%.4Lf\n", 4.99999999l);
	printf("%.4Lf\n", 19.99999999l);
	printf("%.20Lf\n", 191231232.99999999l);
	printf("%.30Lf\n", 191231232.99999999l);
	printf("%.40Lf\n", 191231232.99999999l);
	printf("%.50Lf\n", 191231232.99999999l);
	printf("%.Lf\n", -0.0l);
	printf("%.3Lf\n", -0.0l);
	printf("%.Lf\n", -1.5l);
	printf("%.Lf\n", -1.9l);
	printf("%.Lf\n", -1.1l);
	printf("%.Lf\n", -0.5l);
	printf("%.Lf\n", -9.5l);
	printf("%.3Lf\n", -9.51234l);
	printf("%.3Lf\n", -9.5555l);
	printf("%.3Lf\n", -9.559999l);
	printf("%.3Lf\n", -9.59939l);
	printf("%.3Lf\n", -9.234234l);
	printf("%.3Lf\n", -9.734234l);
	printf("%.3Lf\n", -9.434234l);
	printf("%.7Lf\n", -9.9999999999l);
	printf("%.8Lf\n", -9.9999999999l);
	printf("%.10Lf\n", -9.9999999999l);
	printf("%.3Lf\n", -0.0005l);
	printf("%.10Lf\n", -0.0005l);
	printf("%.12Lf\n", -0.0005l);
	printf("%.12Lf\n", -9.99999999l);
	printf("%.12Lf\n", -0.99999999l);
	printf("%.12Lf\n", -4.99999999l);
	printf("%.14Lf\n", -4.99499999l);
	printf("%.2Lf\n", -4.9999435999l);
	printf("%.1Lf\n", -4.99999999l);
	printf("%.4Lf\n", -4.99999999l);
	printf("%.4Lf\n", -19.99999999l);
	printf("%.20Lf\n", -191231232.99999999l);
	printf("%.30Lf\n", -191231232.99999999l);
	printf("%.40Lf\n\n", -191231232.99999999l);
	printf("%.50Lf\n\n", -191231232.99999999l);
	printf("%+.5f\n\n", 0.000001f);
	printf("% .5f\n\n", 0.000005f);
	printf("%+ .5f\n\n", 0.000009f);
	printf("%012.f\n\n", 9.4f);
	printf("%0-12.f\n\n", 9.5f);
	printf("% 32.f\n\n", 9.9f);
	printf("%+2.f\n\n", 99.9f);
	printf("%-12.10f\n\n", 99.99999999999f);
	printf("%+9.10f\n\n", 99.213981273819123f);
	printf("%+9.10f\n\n", -99.213981273819123f);
	printf("%-.10f\n\n", 42.73819123f);
	printf("%-+1.4f\n\n", 42.42424242f);
	printf("% -14.12f\n\n", 0.0005f);
	printf("%-+.12f\n\n", 1.232323232323f);
	printf("%0 14.12f\n\n", 8363748372381233.1239138432f);
	printf("% -22.2f\n\n", 8363748372381233.1239138432f);
	printf("%+2.3f\n\n", 8363748372381233.1239138432f);
	printf("%-1.3f\n\n", 5.55500000000001f);
	printf("%-19.11f\n\n", 0.000000000001f);
	printf("%+-0 .11f\n\n", 0.000000000005f);
	printf("% -21.11f\n\n", 0.000000000009f);
	printf("%+101.100f\n\n", 0.0005f);
	printf("%+101.100f\n\n", -0.0005f);
}
