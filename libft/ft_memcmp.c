/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:59:26 by hoale             #+#    #+#             */
/*   Updated: 2024/11/08 14:51:13 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i)
			&& i < n - 1)
		i++ ;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char str1[] = {-128, 0, 127, 0};
	char str2[] = {0, 0, 127, 0};
	printf("%i\n", memcmp(str2,str1, 1));
	printf("%i", ft_memcmp(str2,str1, 1));
}
*/