/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:43:32 by hoale             #+#    #+#             */
/*   Updated: 2024/11/11 13:37:24 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && len == 0)
		return (0);
	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *)(big + i));
		}
		i++ ;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main()
{
	const char	big[] = "aaabcabcd";
	const char	lil[] = "w";

	printf("%s\n", strnstr(big, "cd", 8));
	printf("%s", ft_strnstr(big, "cd", 8));
	return (0);
}
*/