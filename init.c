/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:05 by hoale             #+#    #+#             */
/*   Updated: 2025/03/03 17:29:52 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++ ;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		nbr = nbr * 10 + (str[i] - '0');
		i++ ;
	}
	if (str[0] == '-')
		nbr = -nbr;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (FALSE);
	else
		return (TRUE);
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
			return (FALSE);
		prev = node->value;
		node = node->next;
	}
	return (TRUE);
}
