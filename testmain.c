/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:56:24 by atenhune          #+#    #+#             */
/*   Updated: 2022/03/14 17:21:44 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define KCYN  "\x1B[36m"
#define KMAG  "\x1B[35m"
#define KYEL  "\x1B[33m"
#define KGRN  "\x1B[32m"

int main(void)
{
	int d = -123;
	long ld = -100200300400500;
	long long lld = 111222333444555666;

	printf("%s--------------TESTS WITH INTEGER--------------\n\n", KGRN);

	printf("%sPLUS FLAGS\n\n", KYEL);
	printf("%s\t%%+d\n\n", KMAG);
	printf("XX %+d XX\n", d);
	ft_printf("XX %+d XX\n\n", d);
	printf("%s\t%%+12d\n\n", KCYN);
	printf("XX %+12d XX\n", d);
	ft_printf("XX %+12d XX\n\n", d);
	printf("%s\t%%+012d\n\n", KMAG);
	printf("XX %+012d XX\n", d);
	ft_printf("XX %+012d XX\n\n", d);
	printf("%s\t%%+-12d\n\n", KCYN);
	printf("XX %+-12d XX\n", d);
	ft_printf("XX %+-12d XX\n\n", d);
	printf("%s\t%%+-d\n\n", KMAG);
	printf("XX %+-d XX\n", d);
	ft_printf("XX %+-d XX\n\n", d);

	printf("%sMINUS FLAGS\n\n", KYEL);
	printf("%s\t%%-d\n\n", KCYN);
	printf("XX %-d XX\n", d);
	ft_printf("XX %-d XX\n\n", d);
	printf("%s\t%%-12d\n\n", KMAG);
	printf("XX %-12d XX\n", d);
	ft_printf("XX %-12d XX\n\n", d);
	printf("%s\t%%- d\n\n", KCYN);
	printf("XX % -d XX\n", d);
	ft_printf("XX % -d XX\n\n", d);
	printf("%s\t%%-12d\n\n", KMAG);
	printf("XX %-12d XX\n", d);
	ft_printf("XX %-12d XX\n\n", d);

	printf("%sZERO FLAGS\n\n", KYEL);
	printf("%s\t%%0d\n\n", KCYN);
	printf("XX %0d XX\n", d);
	ft_printf("XX %0d XX\n\n", d);
	printf("%s\t%%012d\n\n", KMAG);
	printf("XX %012d XX\n", d);
	ft_printf("XX %012d XX\n\n", d);
	printf("%s\t%%+0d\n\n", KCYN);
	printf("XX %+0d XX\n", d);
	ft_printf("XX %+0d XX\n\n", d);
	printf("%s\t%%+012d\n\n", KMAG);
	printf("XX %+012d XX\n", d);
	ft_printf("XX %+012d XX\n\n", d);

	printf("%sSPACE FLAGS\n\n", KYEL);
	printf("%s\t%%' 'd\n\n", KCYN);
	printf("XX % d XX\n", d);
	ft_printf("XX % d XX\n\n", d);
	printf("%s\t%%- d\n\n", KMAG);
	printf("XX %- d XX\n", d);
	ft_printf("XX %- d XX\n\n", d);
	printf("%s\t%%0 d\n\n", KCYN);
	printf("XX % 0d XX\n", d);
	ft_printf("XX % 0d XX\n\n", d);	
	printf("%s\t%%0 12d\n\n", KMAG);
	printf("XX %0 12d XX\n", d);
	ft_printf("XX %0 12d XX\n\n", d);

	printf("%s--------------TESTS WITH LONG INTEGER--------------\n\n", KGRN);

	printf("%sPLUS FLAGS\n\n", KYEL);
	printf("%s\t%%+ld\n\n", KMAG);
	printf("XX %+ld XX\n", ld);
	ft_printf("XX %+ld XX\n\n", ld);
	printf("%s\t%%+32ld\n\n", KCYN);
	printf("XX %+32ld XX\n", ld);
	ft_printf("XX %+32ld XX\n\n", ld);
	printf("%s\t%%+032ld\n\n", KMAG);
	printf("XX %+032ld XX\n",ld);
	ft_printf("XX %+032ld XX\n\n", ld);
	printf("%s\t%%+-32ld\n\n", KCYN);
	printf("XX %+-32ld XX\n", ld);
	ft_printf("XX %+-32ld XX\n\n", ld);
	printf("%s\t%%+-ld\n\n", KMAG);
	printf("XX %+-ld XX\n", ld);
	ft_printf("XX %+-ld XX\n\n", ld);

	printf("%sMINUS FLAGS\n\n", KYEL);
	printf("%s\t%%-ld\n\n", KCYN);
	printf("XX %-ld XX\n", ld);
	ft_printf("XX %-ld XX\n\n", ld);
	printf("%s\t%%-32ld\n\n", KMAG);
	printf("XX %-32ld XX\n", ld);
	ft_printf("XX %-32ld XX\n\n", ld);
	printf("%s\t%%- ld\n\n", KCYN);
	printf("XX % -ld XX\n", ld);
	ft_printf("XX % -ld XX\n\n", ld);
	printf("%s\t%%-32ld\n\n", KMAG);
	printf("XX %-32ld XX\n", ld);
	ft_printf("XX %-32ld XX\n\n", ld);

	printf("%sZERO FLAGS\n\n", KYEL);
	printf("%s\t%%0ld\n\n", KCYN);
	printf("XX %0ld XX\n", ld);
	ft_printf("XX %0ld XX\n\n", ld);
	printf("%s\t%%032ld\n\n", KMAG);
	printf("XX %032ld XX\n", ld);
	ft_printf("XX %032ld XX\n\n", ld);
	printf("%s\t%%+0ld\n\n", KCYN);
	printf("XX %+0ld XX\n", ld);
	ft_printf("XX %+0ld XX\n\n", ld);
	printf("%s\t%%+032ld\n\n", KMAG);
	printf("XX %+032ld XX\n", ld);
	ft_printf("XX %+032ld XX\n\n", ld);

	printf("%sSPACE FLAGS\n\n", KYEL);
	printf("%s\t%%' 'ld\n\n", KCYN);
	printf("XX % ld XX\n", ld);
	ft_printf("XX % ld XX\n\n", ld);
	printf("%s\t%%- ld\n\n", KMAG);
	printf("XX %- ld XX\n", ld);
	ft_printf("XX %- ld XX\n\n", ld);
	printf("%s\t%%0 ld\n\n", KCYN);
	printf("XX % 0ld XX\n", ld);
	ft_printf("XX % 0ld XX\n\n", ld);	
	printf("%s\t%%0 32ld\n\n", KMAG);
	printf("XX %0 32ld XX\n", ld);
	ft_printf("XX %0 32ld XX\n\n", ld);

	printf("%s--------------TESTS WITH LONG LONG INTEGER--------------\n\n", KGRN);

	printf("%sPLUS FLAGS\n\n", KYEL);
	printf("%s\t%%+lld\n\n", KMAG);
	printf("XX %+lld XX\n", lld);
	ft_printf("XX %+lld XX\n\n", lld);
	printf("%s\t%%+32lld\n\n", KCYN);
	printf("XX %+32lld XX\n", lld);
	ft_printf("XX %+32lld XX\n\n", lld);
	printf("%s\t%%+032lld\n\n", KMAG);
	printf("XX %+032lld XX\n",lld);
	ft_printf("XX %+032lld XX\n\n", lld);
	printf("%s\t%%+-32lld\n\n", KCYN);
	printf("XX %+-32lld XX\n", lld);
	ft_printf("XX %+-32lld XX\n\n", lld);
	printf("%s\t%%+-lld\n\n", KMAG);
	printf("XX %+-lld XX\n", lld);
	ft_printf("XX %+-lld XX\n\n", lld);

	printf("%sMINUS FLAGS\n\n", KYEL);
	printf("%s\t%%-lld\n\n", KCYN);
	printf("XX %-lld XX\n", lld);
	ft_printf("XX %-lld XX\n\n", lld);
	printf("%s\t%%-12lld\n\n", KMAG);
	printf("XX %-12lld XX\n", lld);
	ft_printf("XX %-12lld XX\n\n", lld);
	printf("%s\t%%- lld\n\n", KCYN);
	printf("XX % -lld XX\n", lld);
	ft_printf("XX % -lld XX\n\n", lld);
	printf("%s\t%%-12lld\n\n", KMAG);
	printf("XX %-12lld XX\n", lld);
	ft_printf("XX %-12lld XX\n\n", lld);

	printf("%sZERO FLAGS\n\n", KYEL);
	printf("%s\t%%0lld\n\n", KCYN);
	printf("XX %0lld XX\n", lld);
	ft_printf("XX %0lld XX\n\n", lld);
	printf("%s\t%%032lld\n\n", KMAG);
	printf("XX %032lld XX\n", lld);
	ft_printf("XX %032lld XX\n\n", lld);
	printf("%s\t%%+0lld\n\n", KCYN);
	printf("XX %+0lld XX\n", lld);
	ft_printf("XX %+0lld XX\n\n", lld);
	printf("%s\t%%+032lld\n\n", KMAG);
	printf("XX %+032lld XX\n", lld);
	ft_printf("XX %+032lld XX\n\n", lld);

	printf("%sSPACE FLAGS\n\n", KYEL);
	printf("%s\t%%' 'lld\n\n", KCYN);
	printf("XX % lld XX\n", lld);
	ft_printf("XX % lld XX\n\n", lld);
	printf("%s\t%%- lld\n\n", KMAG);
	printf("XX %- lld XX\n", lld);
	ft_printf("XX %- lld XX\n\n", lld);
	printf("%s\t%%0 lld\n\n", KCYN);
	printf("XX % 0lld XX\n", lld);
	ft_printf("XX % 0lld XX\n\n", lld);	
	printf("%s\t%%0 32lld\n\n", KMAG);
	printf("XX %0 32lld XX\n", lld);
	ft_printf("XX %0 32lld XX\n\n", lld);


}