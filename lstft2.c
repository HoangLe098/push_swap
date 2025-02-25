/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:21 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 18:44:58 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*Return the index of target node in stack A for an B node
Target node has closest smaller value 
Find max value if no smaller value found*/
int	target4b(int b_value, t_list *sa)
{
	t_list	*ptra;
	int		min_d;
	int		target_index;

	ptra = sa;
	min_d = -1;
	while (ptra)
	{
		if (ptra->value <= b_value)
		{
			if (min_d == -1 || b_value - ptra->value < min_d)
			{
				min_d = b_value - ptra->value;
				target_index = ptra->index;
			}
		}
		ptra = ptra->next;
	}
	if (min_d < 0)
		target_index = max_node(sa).index;
	return (target_index);
}

/*Return the index of target node in stack A for an B node
Target node has closest bigger value 
Find min value if no bigger value found*/
int	target4a(int a_value, t_list *sb)
{
	t_list	*ptrb;
	int		min_d;
	int		target_index;

	ptrb = sb;
	min_d = -1;
	while (ptrb)
	{
		if (ptrb->value >= a_value)
		{
			if (min_d == -1 || ptrb->value - a_value < min_d)
			{
				min_d = ptrb->value - a_value;
				target_index = ptrb->index;
			}
		}
		ptrb = ptrb->next;
	}
	if (min_d < 0)
		target_index = min_node(sb).index;
	return (target_index);
}
