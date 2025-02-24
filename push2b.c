/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:13:47 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 18:46:01 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Return cost to bring the b node and target to top
struct s_cost	cost_b2top(t_list *sa, t_list *sb, t_list *bnode)
{
	int				target;
	int				bota;
	int				botb;
	struct s_cost	b;

	target = target4b(bnode->value, sa);
	bota = ft_lstsize(sa) - target;
	botb = ft_lstsize(sb) - bnode->index;
	b.cost = min4(max2(target, bnode->index),
			max2(bota, botb),
			target + botb,
			bota + bnode->index);
	if (b.cost == max2(target, bnode->index))
		b.rot_method = 1;
	else if (b.cost == max2(bota, botb))
		b.rot_method = 2;
	else if (b.cost == target + botb)
		b.rot_method = 3;
	else if (b.cost == bota + bnode->index)
		b.rot_method = 4;
	return (b);
}

//Return positions of cheapest node b
t_list	*cheapest_b(t_list *sa, t_list *sb)
{
	t_list	*cur;
	int		cur_cost;
	t_list	*cheap_node;
	int		cheap_cost;

	cheap_node = sb;
	cheap_cost = cost_b2top(sa, sb, sb).cost;
	cur = sb;
	while (cur)
	{
		cur_cost = cost_b2top(sa, sb, cur).cost;
		if (cur_cost < cheap_cost)
		{
			cheap_cost = cur_cost;
			cheap_node = cur;
		}
		cur = cur->next;
	}
	return (cheap_node);
}

//Move the cheapest node b and its target to the tops
void	cheapb2top(t_list **sa, t_list **sb)
{
	t_list	*cheap_node;
	int method;

	cheap_node = cheapest_b(*sa, *sb);
	method = cost_b2top(*sa, *sb, cheap_node).rot_method;
	if (method == 1)
		upup(sa, target4b(cheap_node->value, *sa), sb, cheap_node->index);
	else if (method == 2)
		downdown(sa, target4b(cheap_node->value, *sa), sb, cheap_node->index);
	else if (method == 3)
		updown(sa, target4b(cheap_node->value, *sa), sb, cheap_node->index);
	else if (method == 4)
		downup(sa, target4b(cheap_node->value, *sa), sb, cheap_node->index);
}
