/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:13:47 by hoale             #+#    #+#             */
/*   Updated: 2025/03/06 17:29:31 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Return the index of target node in stack B for an A node
Target node has closest smaller value 
Find max value if no smaller value found*/
int	target4a(int a_value, t_list *sb)
{
	t_list		*ptrb;
	long long	min_d;
	long long	lla;
	long long	llb;
	int			target_index;

	ptrb = sb;
	min_d = -1;
	while (ptrb)
	{
		if (ptrb->value <= a_value)
		{
			lla = (long long)a_value;
			llb = (long long)ptrb->value;
			if (min_d == -1 || lla - llb < min_d)
			{
				min_d = lla - llb;
				target_index = ptrb->index;
			}
		}
		ptrb = ptrb->next;
	}
	if (min_d < 0)
		target_index = max_node(sb).index;
	return (target_index);
}

//Return cost to bring the a node and target to top
struct s_cost	cost_a2top(t_list *sa, t_list *sb, t_list *anode)
{
	int				target;
	int				bota;
	int				botb;
	struct s_cost	a;

	target = target4a(anode->value, sb);
	bota = ft_lstsize(sa) - anode->index;
	botb = ft_lstsize(sb) - target;
	a.cost = min4(max2(anode->index, target),
			max2(bota, botb),
			anode->index + botb,
			bota + target);
	if (a.cost == max2(anode->index, target))
		a.rot_method = 1;
	else if (a.cost == max2(bota, botb))
		a.rot_method = 2;
	else if (a.cost == anode->index + botb)
		a.rot_method = 3;
	else if (a.cost == bota + target)
		a.rot_method = 4;
	return (a);
}

//Return positions of cheapest node b
t_list	*cheapest_a(t_list *sa, t_list *sb)
{
	t_list	*cur;
	int		cur_cost;
	t_list	*cheap_node;
	int		cheap_cost;

	cheap_node = sa;
	cheap_cost = cost_a2top(sa, sb, sa).cost;
	cur = sa;
	while (cur)
	{
		cur_cost = cost_a2top(sa, sb, cur).cost;
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
void	cheapa2top(t_list **sa, t_list **sb)
{
	t_list	*cheap_node;
	int		method;

	cheap_node = cheapest_a(*sa, *sb);
	method = cost_a2top(*sa, *sb, cheap_node).rot_method;
	if (method == 1)
		upup(sa, cheap_node->index, sb, target4a(cheap_node->value, *sb));
	else if (method == 2)
		downdown(sa, cheap_node->index, sb, target4a(cheap_node->value, *sb));
	else if (method == 3)
		updown(sa, cheap_node->index, sb, target4a(cheap_node->value, *sb));
	else if (method == 4)
		downup(sa, cheap_node->index, sb, target4a(cheap_node->value, *sb));
}
