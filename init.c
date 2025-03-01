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

static int	is_integer(char *str)
{
	int 		i;
	long long	nbr;

	i = 0;
	if (str[i] = '-')
		i++ ;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		nbr = nbr * 10 + (str[i] - '0')
		i++ ;
	}
	if (str[0] == '-')
		nbr = -nbr;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (FALSE);
	else
		return (TRUE);
}

static int	is_duplicate(char **av, int start)
{
	int	i;
	int	j;

	i = start;
	while (av[i])
	{
		j = start;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]) && i != j)
				return (TRUE);
			j++ ;
		}
		i++ ;
	}
	return (FALSE);
}

int	valid_check(char **av, int start)
{
	int	i;

	i = start;
	while (av[i])
	{
		if (is_integer(av[i]) == FALSE)
			return (FALSE);
		i++ ;
	}
	if (is_duplicate(av, start) == TRUE)
		return (FALSE);
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
			return (FALSE);
		prev = node->value;
		node = node->next;
	}
	return (TRUE);
}
