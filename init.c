#include "push_swap.h"

int	valid_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > '9' && av[i][j] <'0')
				return (0);
			j++ ;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i] < INT_MIN))
			return (0);
		i++ ;
	}
	return (1);
}

t_list	*stack_init(char **av)
{
	t_list	*stack;
	int		i;

	stack = ft_lstnew(ft_atoi(av[1]));
	if (!stack)
		return (NULL);
	i = 2;
	while (av[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
		i++ ;
	}
	index_stack(stack);
	return (stack);
}

int	is_sort(t_list *stack)
{
	t_list	*node;
	int		prev;

	node = stack;
	prev = node->value;
	node = node->next;
	while (node)
	{
		if (node->value <= prev)
			return (0);
		prev = node->value;
		node = node->next;
	}
	return(1);
}

int	is_repeat(t_list *stack)
{
	t_list	*p1;
	t_list	*p2;

	p1 = stack;
	while (p1->next)
	{
		p2 = p1->next;
		while (p2)
		{
			if (p2->value == p1->value)
				return (1);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (0);
}
