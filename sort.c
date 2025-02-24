/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:29:01 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 18:46:22 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	if (ft_lstsize(*stack) < 3)
	{
		if (max_node(*stack).index < ft_lstsize(*stack) - 1)
			rotate(stack, 'a');
		return ;
	}
	if (max_node(*stack).index == 0)
		rotate(stack, 'a');
	if (max_node(*stack).index == 1)
		rev_rotate(stack, 'a');
	if (min_node(*stack).index == 1)
		swap(*stack, 'a');
}

void	min2top(t_list **stack)
{
	int	i;
	int	min_pos;

	min_pos = min_node(*stack).index;
	i = -1;
	if (min_pos < ft_lstsize(*stack) / 2)
	{
		while (i++ < min_pos)
			rotate(stack, 'a');
	}
	else
	{
		while (i++ < ft_lstsize(*stack) - min_pos)
			rotate(stack, 'a');
	}
}

void	sort(t_list **sa, t_list **sb)
{
	pb(sa, sb);
	pb(sa, sb);
	while (ft_lstsize(*sa) > 3)
	{
		cheapb2top(sa, sb);
		pb(sa, sb);
	}
	sort_three(sa);
	while (ft_lstsize(*sb) > 0)
	{
		cheapb2top(sa, sb);
		pa(sa, sb);
	}
	min2top(sa);
}
