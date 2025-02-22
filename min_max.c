/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:35 by hoale             #+#    #+#             */
/*   Updated: 2025/02/22 15:14:36 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int count, ...)
{
	int	*args;
	int	max_value;
	int	i;

	args = &count + 1;
	max_value = *args;
	i = 1;
	while (i < count)
	{
		if (*(args + i) > max_value)
			max_value = *(args + i);
		i++ ;
	}
	return (max_value);
}

int	min(int count, ...)
{
	int	*args;
	int	min_value;
	int	i;

	args = &count + 1;
	min_value = *args;
	i = 1;
	while (i < count)
	{
		if (*(args + i) < min_value)
			min_value = *(args + i);
		i++ ;
	}
	return (min_value);
}
