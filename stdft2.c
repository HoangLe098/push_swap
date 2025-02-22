/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:15:00 by hoale             #+#    #+#             */
/*   Updated: 2025/02/22 15:45:28 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char s)
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
	if (s == 'a')
		ft_printf("r%c\n", s);
	else if (s == 'b')
		ft_printf("r%c\n", s);
}

void	rr(t_list **sa, t_list **sb)
{
	rotate(sa, 'c');
	rotate(sb, 'c');
	ft_printf("rr\n");
}

void	rev_rotate(t_list **stack, char s)
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
	if (s == 'a')
		ft_printf("rr%c\n", s);
	else if (s == 'b')
		ft_printf("rr%c\n", s);
}

void	rrr(t_list **sa, t_list **sb)
{
	rev_rotate(sa, 'c');
	rev_rotate(sb, 'c');
	ft_printf("rrr\n");
}
