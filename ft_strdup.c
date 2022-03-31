/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:42:26 by atenhune          #+#    #+#             */
/*   Updated: 2022/03/19 11:36:04 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup = ft_strnew(len);
	if (s == NULL)
		return (dup);
	if (dup == NULL)
		return (dup);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
