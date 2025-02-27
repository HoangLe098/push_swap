/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:05 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:35:32 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_check(char **av, int start)
{
	int	i;
	int	j;

	i = start;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] > '9' || av[i][j] < '0')
			&& av[i][j] != '-' && av[i][j] != '+')
				return (FALSE);
			j++ ;
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (FALSE);
		i++ ;
	}
	return (TRUE);
}

t_list	*stack_init(char **av, int start)
{
	t_list	*stack;
	int		i;

	stack = ft_lstnew(ft_atoi(av[start]));
	if (!stack)
		return (NULL);
	i = start + 1;
	while (av[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
		i++ ;
	}
	index_stack(stack);
	return (stack);
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++ ;
	}
	free(arg);
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
	return (1);
}

int	is_duplicate(t_list *stack)
{
	t_list	*p1;
	t_list	*p2;

	p1 = stack;
	while (p1)
	{
		p2 = stack;
		while (p2)
		{
			if (p1->value == p2->value && p1->index != p2->index)
				return (TRUE);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (FALSE);
}
