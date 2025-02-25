/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:08:04 by hoale             #+#    #+#             */
/*   Updated: 2024/11/08 15:54:25 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && s1[i] == s2[i] && i < n -1)
		i++ ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char str1[] = "ava";
	char str2[] = "avb";
	printf("%i\n", strncmp(str1,str2, 2));
	printf("%i", ft_strncmp(str1,str2, 2));
}
*/