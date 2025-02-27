/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:21 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 16:14:09 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	index_stack(t_list *lst)
{
	t_list	*iter;
	int		i;

	if (!lst)
		return ;
	iter = lst;
	i = 0;
	while (iter)
	{
		iter->index = i;
		iter = iter->next;
		i++ ;
	}
}
