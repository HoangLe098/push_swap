#include "push_swap.h"

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

//Return positions of cheapest node a
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

//Move the cheapest node a and its target to the tops
void	cheapa2top(t_list **sa, t_list **sb)
{
	t_list	*cheap_node;
	int method;

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