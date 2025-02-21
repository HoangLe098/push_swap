#include "push_swap.h"

//Return cost to bring the b node and target to top
int	cost_b2top(t_list *sa, t_list *sb, t_list *bnode)
{
	int target;
	int bota;
	int botb;

	target = target4b(bnode->value, sa);
	bota = ft_lstsize(sa) - target;
	botb = ft_lstsize(sb) - bnode->index;
	return (min(4,
				max(2, target, bnode->index),
				max(2, bota, botb),
				target + botb,
				bota + bnode->index));
}

//Return positions of cheapest node b
int	cheapest_b(t_list *sa, t_list *sb)
{
	t_list	*cur;
	int		cur_cost;
	int		cheap_cost;
	int		cheap_node;

	cheap_node = sb->index;
	cheap_cost = cost_b2top(sa, sb, sb);
	cur = sb;
	while (cur)
	{
		cur_cost = cost_b2top(sa, sb, cur);
		if (cur_cost < cheap_cost)
		{
			cheap_cost = cur_cost;
			cheap_node = cur->index;
		}
		cur = cur->next;
	}
	return (cheap_node);
}

//Move the cheapest node b and its target to the tops
void	cheapb2top(t_list **sa, t_list **sb)
{

}