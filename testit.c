/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:43 by antti             #+#    #+#             */
/*   Updated: 2022/03/29 14:30:03 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define KCYN  "\x1B[36m"
#define KMAG  "\x1B[35m"
#define KYEL  "\x1B[33m"
#define KGRN  "\x1B[32m"
#define KRED  "\x1B[31m"

int main(void)
{
	printf("%s('%%d', 42)\t%s[OK]\n", KYEL, KGRN);
	printf("%s('%%12d', 42)\t%s[OK]\n", KYEL, KGRN);
	printf("%s('%%+13d', 42)\t%s[OK]\n", KYEL, KGRN);
	printf("%s('%%+1.5d', 42)\t%s[FAIL]\n", KYEL, KRED);
	
}