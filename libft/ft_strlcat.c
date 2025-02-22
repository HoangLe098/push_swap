/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:05:05 by hoale             #+#    #+#             */
/*   Updated: 2024/11/11 13:36:39 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	if (size == 0)
	{
		if (dst == NULL)
			return (ft_strlen(src));
		else
			return (ft_strlen(src));
	}
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen > size)
		dlen = size;
	if (dlen == size)
		return (size + slen);
	i = 0;
	while (i < slen && dlen + i + 1 < size)
	{
		dst[dlen + i] = src[i];
		i++ ;
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main()
{
	char	src[] = "nyan !";
	printf("%zu", strlcat(NULL,src, 0));
}
*/
