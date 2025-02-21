#include "push_swap.h"

void	swap(t_list *stack)
{
	int tmp;

	tmp = 0;
	if (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
}

void	ss(t_list *sa, t_list *sb)
{
	int tmp;

	tmp = 0;
	if (sa->next)
	{
		tmp = sa->value;
		sa->value = sa->next->value;
		sa->next->value = tmp;
	}
	if (sb->next)
	{
		tmp = sb->value;
		sb->value = sb->next->value;
		sb->next->value = tmp;
	}
}

void	pb(t_list **sa, t_list **sb)
{
	t_list	*tmp;

	if (!*sa)
		return;
	tmp = *sa;
	tmp = tmp->next;
	(*sa)->next = *sb;
	*sb = *sa;
	*sa = tmp;
	index_stack(*sa);
	index_stack(*sb);
}

void	pa(t_list **sa, t_list **sb)
{
	t_list	*tmp;

	if (!*sb)
		return;
	tmp = *sb;
	tmp = tmp->next;
	(*sb)->next = *sa;
	*sa = *sb;
	*sb = tmp;
	index_stack(*sa);
	index_stack(*sb);
}