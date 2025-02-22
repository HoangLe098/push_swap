/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:15:09 by hoale             #+#    #+#             */
/*   Updated: 2024/10/31 16:41:02 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	minus;

	result = 0;
	i = 0;
	minus = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\t')
		|| (nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++ ;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++ ;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++ ;
	}
	return (result * minus);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	nb[] = "1";
	printf("%i\n", ft_atoi(nb));
	printf("%i", atoi(nb));
}
*/