/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:16 by hoale             #+#    #+#             */
/*   Updated: 2024/11/04 11:52:30 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	ptr = s;
	i = 0;
	while (*ptr != 0)
		ptr++ ;
	if (cc == 0)
		return ((char *)ptr);
	while (ptr >= s)
	{
		if (cc == *ptr)
			return ((char *)ptr);
		ptr-- ;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	const char s[10] = "Hello";
	int c = 'l';
	printf("%s", ft_strrchr(s, c));
	return (0);
}
*/