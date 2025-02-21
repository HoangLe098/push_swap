#include "push_swap.h"

node	max_node(t_list *stack)
{
	t_list *ptr;
	node	max;

	ptr = stack;
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

node	min_node(t_list *stack)
{
	t_list *ptr;
	node	min;

	ptr = stack;
	min.value = ptr->value;
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

/*Return the index of target node in stack B for an A node
Target node has closest smaller value 
Find max value if no smaller value found*/
int	target4a(int a_value, t_list *sb)
{
	t_list	*ptrB;
	int		min_d;
	int		target_index;

	ptrB = sb;
	min_d = -1;
	while (ptrB)
	{
		if (ptrB->value <= a_value)
		{
			if (min_d == -1 || a_value - ptrB->value < min_d)
			{
				min_d = a_value - ptrB->value;
				target_index = ptrB->index;
			}
		}
		ptrB = ptrB->next;
	}
	if (min_d < 0)
		target_index = max_node(sb).index;
	return (target_index);
}

/*Return the index of target node in stack A for an B node
Target node has closest bigger value 
Find min value if no bigger value found*/
int	target4b(int b_value, t_list *sa)
{
	t_list	*ptrA;
	int		min_d;
	int		target_index;

	ptrA = sa;
	min_d = -1;
	while (ptrA)
	{
		if (ptrA->value >= b_value)
		{
			if (min_d == -1 || ptrA->value - b_value < min_d)
			{
				min_d = ptrA->value - b_value;
				target_index = ptrA->index;
			}
		}
		ptrA = ptrA->next;
	}
	if (min_d < 0)
		target_index = min_node(sa).index;
	return (target_index);
}
