/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:35 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 17:50:07 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max2(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	min2(int a, int b)
{
	if (b < a)
		return (b);
	else
		return (a);
}

int	min4(int a, int b, int c, int d)
{
	int min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}
