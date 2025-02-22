/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:56:05 by hoale             #+#    #+#             */
/*   Updated: 2024/11/08 15:58:23 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (ft_strlen(src) + 1 < size)
		size = ft_strlen(src) + 1;
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++ ;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

int main(void)
{
    char src[] = "coucou";
    char dest[]= "AAAAAAAAAA";
    ft_strlcpy(dest, src, 8);
	printf("%d", memcmp(src, dest, 7));
    return (0);
}
*/