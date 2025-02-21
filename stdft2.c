
#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*cur;

	if (*stack && (*stack)->next)
	{
    	tmp = *stack;
    	tmp = tmp->next;
    	cur = *stack;
    	while (cur->next)
    		cur = cur->next;
    	cur->next = *stack;
    	(*stack)->next = NULL;
    	*stack = tmp;
    	index_stack(*stack);
	}
}

void	rr(t_list **sa, t_list **sb)
{
	rotate(sa);
	rotate(sb);
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*cur;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		cur = *stack;
		while (cur->next != tmp)
			cur = cur->next;
		cur->next = NULL;
		*stack = tmp;
	}
}

void	rrr(t_list **sa, t_list **sb)
{
	rev_rotate(sa);
	rev_rotate(sb);
}