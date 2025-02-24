/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:53 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 15:44:07 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char s)
{
	int	tmp;

	tmp = 0;
	if (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
	}
	if (s == 'a')
		ft_printf("s%c\n", s);
	else if (s == 'b')
		ft_printf("s%c\n", s);
}

void	ss(t_list *sa, t_list *sb)
{
	swap(sa, 'c');
	swap(sb, 'c');
	ft_printf("ss\n");
}

void	pb(t_list **sa, t_list **sb)
{
	t_list	*tmp;

	if (!*sa)
		return ;
	if (!*sb)
	{
		*sb = *sa;
		*sa = (*sa)->next;
		(*sb)->next = NULL;
	}
	else
	{
		tmp = *sa;
		tmp = tmp->next;
		(*sa)->next = *sb;
		*sb = *sa;
		*sa = tmp;
	}
	index_stack(*sa);
	index_stack(*sb);
	ft_printf("pb\n");
}

void	pa(t_list **sa, t_list **sb)
{
	t_list	*tmp;

	if (!*sb)
		return ;
	if (!*sa)
	{
		*sa = *sb;
		*sb = (*sa)->next;
		(*sa)->next = NULL;
	}
	else
	{
		tmp = *sb;
		tmp = tmp->next;
		(*sb)->next = *sa;
		*sa = *sb;
		*sb = tmp;
	}
	index_stack(*sa);
	index_stack(*sb);
	ft_printf("pa\n");
}
