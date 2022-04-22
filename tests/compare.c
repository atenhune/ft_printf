/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:07:51 by atenhune          #+#    #+#             */
/*   Updated: 2022/04/22 13:50:50 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define GREEN  "\x1B[32m"
#define RED  "\x1B[31m"
#define KMAG  "\x1B[35m"

int main(int argc, char **argv)
{
	char buff[100000];
	int fd;
	int i = 0;
	int j = 0;
	int count = 1;
	int read_ret;
	int offset = 18;
	printf("\n%s%s:\n", KMAG, argv[2]);
	fd = open(argv[1], O_RDONLY);
	read_ret = read(fd, buff, 10000);
	while(i < read_ret)
	{
		if(count % 30 == 0 && j != 1)
		{
			printf("\n");
			j = 1;
		}
		if(buff[i]=='\n')
		{
			printf("%s[OK]", GREEN);
			count++;
			j = 0; 
		}
		if(buff[i]== '|')
		{
			printf("%s[FAIL](%d)", RED, count + offset);
			count++;
			j = 0; 
		}
		i++;
	}
	close(fd);


}