/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:35 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 15:23:57 by hoale            ###   ########.fr       */
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
struct s_node	max_node(t_list *stack)
{
	t_list			*ptr;
	struct s_node	max;

	ptr = stack;
	max.index = ptr->index;
	max.value = ptr->value;
	while (ptr)
	{
		if (ptr->value > max.value)
		{
			max.value = ptr->value;
			max.index = ptr->index;
		}
		ptr = ptr->next;
	}
	return (max);
}

struct s_node	min_node(t_list *stack)
{
	t_list			*ptr;
	struct s_node	min;

	ptr = stack;
	min.value = ptr->value;
	min.index = ptr->index;
	while (ptr)
	{
		if (ptr->value < min.value)
		{
			min.value = ptr->value;
			min.index = ptr->index;
		}
		ptr = ptr->next;
	}
	return (min);
}
