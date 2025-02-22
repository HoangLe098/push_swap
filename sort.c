/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:29:01 by hoale             #+#    #+#             */
/*   Updated: 2025/02/22 15:49:06 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	if (ft_lstsize(*stack) != 3)
		return ;
	if (max_node(*stack).index == 0)
		rotate(stack);
	if (max_node(*stack).index == 1)
		rev_rotate(stack);
	if (min_node(*stack).index == 1)
		swap(stack);
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
		cheapa2top(sa, sb);
		pa(sa, sb);
	}
	min2top(sa);
}
